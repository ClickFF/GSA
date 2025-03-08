# include <stdio.h>
# include <math.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# define MAXCHAR 2560
# define COLORTEXT "YES"
//this program standlize pdb file*/
char ifilename[MAXCHAR];
char ofilename[MAXCHAR];
char line[MAXCHAR];
char name[MAXCHAR];
char fs[MAXCHAR];
FILE *fpin, *fpout;

void convert() {
int i;
	fprintf(fpout, "%s\t", name);
	for(i=0; i<strlen(fs); i++) {
		if(fs[i] == '0') fprintf(fpout, "%c %c %c %c ", '0','0','0','0');
		if(fs[i] == '1') fprintf(fpout, "%c %c %c %c ", '0','0','0','1');
		if(fs[i] == '2') fprintf(fpout, "%c %c %c %c ", '0','0','1','0');
		if(fs[i] == '3') fprintf(fpout, "%c %c %c %c ", '0','0','1','1');
		if(fs[i] == '4') fprintf(fpout, "%c %c %c %c ", '0','1','0','0');
		if(fs[i] == '5') fprintf(fpout, "%c %c %c %c ", '0','1','0','1');
		if(fs[i] == '6') fprintf(fpout, "%c %c %c %c ", '0','1','1','0');
		if(fs[i] == '7') fprintf(fpout, "%c %c %c %c ", '0','1','1','1');
		if(fs[i] == '8') fprintf(fpout, "%c %c %c %c ", '1','0','0','0');
		if(fs[i] == '9') fprintf(fpout, "%c %c %c %c ", '1','0','0','1');
		if(fs[i] == 'a') fprintf(fpout, "%c %c %c %c ", '1','0','1','0');
		if(fs[i] == 'b') fprintf(fpout, "%c %c %c %c ", '1','0','1','1');
		if(fs[i] == 'c') fprintf(fpout, "%c %c %c %c ", '1','1','0','0');
		if(fs[i] == 'd') fprintf(fpout, "%c %c %c %c ", '1','1','0','1');
		if(fs[i] == 'e') fprintf(fpout, "%c %c %c %c ", '1','1','1','0');
		if(fs[i] == 'f') fprintf(fpout, "%c %c %c %c ", '1','1','1','1');
		if(fs[i] == 'A') fprintf(fpout, "%c %c %c %c ", '1','0','1','0');
		if(fs[i] == 'B') fprintf(fpout, "%c %c %c %c ", '1','0','1','1');
		if(fs[i] == 'C') fprintf(fpout, "%c %c %c %c ", '1','1','0','0');
		if(fs[i] == 'D') fprintf(fpout, "%c %c %c %c ", '1','1','0','1');
		if(fs[i] == 'E') fprintf(fpout, "%c %c %c %c ", '1','1','1','0');
		if(fs[i] == 'F') fprintf(fpout, "%c %c %c %c ", '1','1','1','1');
	}
	fprintf(fpout, "\n");
}

int main(int argc, char *argv[]) {
	int i;
	int count = 0;
	int atomnum;
	double x, y, z;
	if (strcmp(COLORTEXT, "YES") == 0 || strcmp(COLORTEXT, "yes") == 0) {
		if (argc == 2
			&& (strcmp(argv[1], "-h") == 0
				|| strcmp(argv[1], "-H") == 0)) {
			printf
				("[31mUsage: hex2bin -i[0m input file name in hex fingerprint format \n"
				 "[31m               -o[0m output file name in binary descriptor format\n");
			exit(0);
		}
		if (argc != 5) {
			printf
				("[31mUsage: hex2bin -i[0m input file name in hex fingerprint format \n"
				 "[31m               -o[0m output file name in binary descriptor format\n");
			exit(0);
		}
	} else {
		if (argc == 2
			&& (strcmp(argv[1], "-h") == 0
				|| strcmp(argv[1], "-H") == 0)) {
			printf
				("Usage: hex2bin -i input file name in hex fingerprint format \n"
				 "               -o output file name in binary descriptor format\n");
			exit(0);
		}
		if (argc != 5) {
			printf
				("Usage: hex2bin -i input file name in hex fingerprint format \n"
				 "               -o output file name in binary descriptor format\n");
			exit(0);
		}

	}

	for (i = 1; i < argc; i += 2) {
		if (strcmp(argv[i], "-i") == 0)  
			strcpy(ifilename, argv[i + 1]);
		if (strcmp(argv[i], "-o") == 0)  
			strcpy(ofilename, argv[i + 1]);
	}
	if ((fpin = fopen(ifilename, "r")) == NULL) {
        	fprintf(stderr, "Cannot open file %s, exit\n", ifilename);
        	exit(1);
	}
	if ((fpout = fopen(ofilename, "w")) == NULL) {
        	fprintf(stderr, "Cannot open file %s, exit\n", ofilename);
        	exit(1);
	}
        for (;;) {
                if (fgets(line, MAXCHAR, fpin) == NULL) break;
		if (line[0] == '#') continue;
		if (strlen(line) <= 1) break;
		strcpy(fs,   "#######");
		strcpy(name, "#######");
		sscanf(line, "%s%s", fs, name);
		if(strcmp(name, "#######") == 0) continue;
		convert();
        }

fclose(fpin);
fclose(fpout);
return 0;
}
