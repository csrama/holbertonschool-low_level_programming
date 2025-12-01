#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err_exit(char *msg) { dprintf(2, "%s\n", msg), exit(98); }

void print_magic(unsigned char *e)
{
	int i; printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

void print_class(unsigned char *e)
{
	printf("  Class:                             ");
	printf(e[EI_CLASS] == ELFCLASS32 ? "ELF32\n" :
	       e[EI_CLASS] == ELFCLASS64 ? "ELF64\n" :
	       e[EI_CLASS] == ELFCLASSNONE ? "none\n" :
	       "<unknown: %x>\n", e[EI_CLASS]);
}

void print_data(unsigned char *e)
{
	printf("  Data:                              ");
	printf(e[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian\n" :
	       e[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian\n" :
	       e[EI_DATA] == ELFDATANONE ? "none\n" :
	       "<unknown: %x>\n", e[EI_DATA]);
}

void print_type(uint16_t t, unsigned char *e)
{
	printf("  Type:                              ");
	if (e[EI_DATA] == ELFDATA2MSB) t = (t >> 8) | (t << 8);
	printf(t == ET_NONE ? "NONE (None)\n" :
	       t == ET_REL ? "REL (Relocatable file)\n" :
	       t == ET_EXEC ? "EXEC (Executable file)\n" :
	       t == ET_DYN ? "DYN (Shared object file)\n" :
	       t == ET_CORE ? "CORE (Core file)\n" :
	       "<unknown: %x>\n", t);
}

int main(int argc, char **argv)
{
	int fd; unsigned char e[EI_NIDENT]; uint16_t t; unsigned long int entry;
	
	if (argc != 2) err_exit("Usage: elf_header elf_filename");
	if ((fd = open(argv[1], O_RDONLY)) == -1) err_exit("Error: Cannot open file");
	if (read(fd, e, EI_NIDENT) != EI_NIDENT) err_exit("Error: Cannot read file");
	if (e[0] != 0x7f || e[1] != 'E' || e[2] != 'L' || e[3] != 'F') err_exit("Error: Not an ELF file");
	
	lseek(fd, 0, SEEK_SET);
	if (e[EI_CLASS] == ELFCLASS32) {
		Elf32_Ehdr h; read(fd, &h, sizeof(h)); t = h.e_type; entry = h.e_entry;
	} else if (e[EI_CLASS] == ELFCLASS64) {
		Elf64_Ehdr h; read(fd, &h, sizeof(h)); t = h.e_type; entry = h.e_entry;
	} else err_exit("Error: Unknown ELF class");
	
	printf("ELF Header:\n");
	print_magic(e); print_class(e); print_data(e);
	printf("  Version:                           %d%s\n", e[EI_VERSION], 
	       e[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       %d\n", e[EI_ABIVERSION]);
	print_type(t, e);
	printf("  Entry point address:               %s0x%lx\n",
	       e[EI_CLASS] == ELFCLASS32 ? "" : "", e[EI_CLASS] == ELFCLASS32 ? (unsigned int)entry : entry);
	
	close(fd); return (0);
}
