//17114047
// C program to determine class, Network 
// and Host ID of an IPv4 address 
/**
* @file 1.c
*
* @author Harsha Vardhan 17114047
*
* @date 22/08/2019
*/
#include<stdio.h> 
#include<string.h> 

// Function to find out the Class 
/**
* This method will be used to print a single character to the lcd.
* @author 17114047
* @param findClass
* @date 22/08/2019
*/
char findClass(char str[]) 
{ 
	// storing first octet in arr[] variable 
	char arr[4]; 
	int i = 0; 
	while (str[i] != '.') 
	{ 
		arr[i] = str[i]; 
		i++; 
	} 
	i--; 

	// converting str[] variable into number for 
	// comparison 
	int ip = 0, j = 1; 
	while (i >= 0) 
	{ 
		ip = ip + (str[i] - '0') * j; 
		j = j * 10; 
		i--; 
	} 

	// Class A 
	if (ip >=1 && ip <= 127) 
		return 'A'; 

	// Class B 
	else if (ip >= 128 && ip <= 191) 
		return 'B'; 

	// Class C 
	else if (ip >= 192 && ip <= 223) 
		return 'C'; 

	// Class D 
	else if (ip >= 224 && ip <= 239) 
		return 'D'; 

	// Class E 
	else
		return 'E'; 
} 

// Function to separate Network ID as well as 
// Host ID and print them 
void separate(char str[], char ipClass) 
{ 
	// Initializing network and host array to NULL 
	char network[12], host[12]; 
	for (int k = 0; k < 12; k++) 
		network[k] = host[k] = '\0'; 

	// class A 
	if (ipClass == 'A') 
	{ 
		int i = 0, j = 0; 
		while (str[j] != '.') 
			network[i++] = str[j++]; 
		i = 0; 
		j++; 
		while (str[j] != '\0') 
			host[i++] = str[j++]; 
		printf("Network ID : %s\n", network); 
		printf("Host ID : %s\n", host); 
	} 

	// class B 
	else if (ipClass == 'B') 
	{ 
		int i = 0, j = 0, dotCount = 0;
		while (dotCount < 2) 
		{ 
			network[i++] = str[j++]; 
			if (str[j] == '.') 
				dotCount++; 
		} 
		i = 0; 
		j++; 

		while (str[j] != '\0') 
			host[i++] = str[j++]; 

		printf("Network ID : %s\n", network); 
		printf("Host ID : %s\n", host); 
	} 

	// class C 
	else if (ipClass == 'C') 
	{ 
		int i = 0, j = 0, dotCount = 0;
		while (dotCount < 3) 
		{ 
			network[i++] = str[j++]; 
			if (str[j] == '.') 
				dotCount++; 
		} 

		i = 0; 
		j++; 

		while (str[j] != '\0') 
			host[i++] = str[j++]; 

		printf("Network ID : %s\n", network); 
		printf("Host ID : %s\n", host); 
	} 

	// Class D and E 
	else
		printf("Class D and E are not divided in Network and Host ID\n"); 
} 
 
int main() 
{ 	
	char str[15];
	printf("Enter IP\n");
	scanf("%s",str); 
	char ipClass = findClass(str); 
	printf("Class %c\n",ipClass); 
	separate(str,ipClass); 
	return 0; 
} 
