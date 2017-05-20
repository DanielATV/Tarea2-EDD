	FILE *fp;
	fp = fopen("input.dat","w");
	int m = 100;
	int n = 9;
	fwrite(&m,sizeof(int),1,fp);
	fwrite(&n,sizeof(int),1,fp);
	
	char str1[]="malloc 10";
	char str2[]="malloc 20";
	char str3[]="malloc 10";
	char str4[]="malloc 40";
	char str5[]="malloc 21";
	char str55[]="free 31";
	char str6[]="malloc 5";
	char str7[]="malloc 10";
	char str8[]="malloc 5";
	
	fwrite(str1,sizeof(str1),1,fp);
	fwrite(str2,sizeof(str2),1,fp);
	fwrite(str3,sizeof(str3),1,fp);
	fwrite(str4,sizeof(str4),1,fp);
	fwrite(str5,sizeof(str5),1,fp);
	fwrite(str55,sizeof(str55),1,fp);
	fwrite(str6,sizeof(str6),1,fp);
	fwrite(str7,sizeof(str7),1,fp);
	fwrite(str8,sizeof(str8),1,fp);
	fclose(fp);
