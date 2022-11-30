#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

typedef struct yearMonthDay YEARMONTHDAY;
struct yearMonthDay
{
	int day;
	int month;
	int year;
};

typedef struct location LOCATION;
struct location
{
	char address[30];
	char number[10];
	char district[20];
	char city[20];
	char state[10];
	char zipCode[10];
};

typedef struct patient PATIENT;
struct patient
{
	char name[40];
	char id[20];
	char telephone[20];
	LOCATION address;
	YEARMONTHDAY birthday;
	char email[40];
	YEARMONTHDAY diagnosis;
	char comorbidities[60];
};

void SetCursorPosition(int XPos, int YPos)
{
	COORD coord;
	coord.X = XPos;
	coord.Y = YPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int fileExists(const char *filename)
{
	FILE * file;
	if (file = fopen(filename, "r"))
	{
		fclose(file);
		return 1;
	}

	return 0;
}

int main()
{
	unsigned int cp = 1252;
	unsigned int cpin = GetConsoleCP();
	unsigned int cpout = GetConsoleOutputCP();

	SetConsoleCP(cp);
	SetConsoleOutputCP(cp);

	if (fileExists("users.txt") == 0)
	{
		FILE * users;
		users = fopen("users.txt", "w");
		fclose(users);
	}

	int option = 0;
	int mayLogin = 0;
	int confirm = 0;

	do {
		system("cls");
		printf("\n  #-------------  CADASTRO DE PACIENTES COM CASOS DE COVID-19  --------------#");
		printf("\n  |                                                                          |");
		printf("\n  |                                                                          |");
		printf("\n  |            1 - REALIZAR LOGIN                                            |");
		printf("\n  |            2 - CRIAR NOVO USUARIO                                        |");
		printf("\n  |                                                                          |");
		printf("\n  |                                                                          |");
		printf("\n  |            0 - SAIR                                                      |");
		printf("\n  |                                                                          |");
		printf("\n  #--------------------------------------------------------------------------#");
		printf("\n\n  > Escolha uma opcao: ");
		scanf("%i", &option);

		switch (option)
		{
			case 1:
				{
					// P�gina de login
					do {
						char login[15];
						char password[15];

						system("cls");
						printf("\n  #-------------  CADASTRO DE PACIENTES COM CASOS DE COVID-19  --------------#");
						printf("\n  |                                                                          |");
						printf("\n  |                                                                          |");
						printf("\n  |                  INSERIR SEUS DADOS DE ACESSO:                           |");
						printf("\n  |                                                                          |");
						printf("\n  |                  LOGIN:                                                  |");
						printf("\n  |                  SENHA:                                                  |");
						printf("\n  |                                                                          |");
						printf("\n  #--------------------------------------------------------------------------#");

						SetCursorPosition(28, 6);
						scanf("%s", &login);

						SetCursorPosition(28, 7);

						int p = 0;

						do {
							password[p] = getch();

							if (password[p] != '\r' && password[p] != '\b')
							{
								printf("*");
							}

							if (password[p] == '\b' && p >= 1)
							{
								p -= 2;
								SetCursorPosition(29 + p, 10);
								printf(" ");
								SetCursorPosition(29 + p, 10);
							}

							p++;

						}

						while (password[p - 1] != '\r');

						password[p - 1] = '\0';

						SetCursorPosition(0, 20);

						FILE * users;
						users = fopen("users.txt", "r");

						char user[15];
						char correctPassword[15];
						int userFound = 0;

						while (fgets(user, sizeof(user), users) != NULL)
						{
							if (strstr(user, login) != NULL)
							{
								userFound = 1;
								fscanf(users, "%[^\n]", correctPassword);
							}
						}

						fclose(users);

						if (userFound == 1)
						{
							if (strstr(password, correctPassword) != NULL)
							{
								mayLogin = 1;
							}
							else
							{
								printf(" [!] Senha incorreta. Pressione ENTER para continuar...");
								mayLogin = 0;
								getch();
							}
						}
						else
						{
							printf(" [!] Usuario nao encontrado. Pressione ENTER para continuar...");
							mayLogin = 0;
							getch();
						}
					}

					while (mayLogin != 1);

					if (fileExists("listaPacientes.txt") == 0)
					{
						FILE * patientList;
						patientList = fopen("listaPacientes.txt", "w");
						fclose(patientList);
					}

					if (fileExists("grupoDeRisco.txt") == 0)
					{
						FILE * riskGroup;
						riskGroup = fopen("grupoDeRisco.txt", "w");
						fclose(riskGroup);
					}

					// Menu Principal
					do {
						system("cls");
						printf("\n  #-------------  CADASTRO DE PACIENTES COM CASOS DE COVID-19  --------------#");
						printf("\n  |                                                                          |");
						printf("\n  |                                                                          |");
						printf("\n  |                             MENU PRINCIPAL                               |");
						printf("\n  |                                                                          |");
						printf("\n  |                                                                          |");
						printf("\n  |            1 - CONSULTAR LISTA DE PACIENTES                              |");
						printf("\n  |            2 - CONSULTAR LISTA DE PACIENTES DO GRUPO DE RISCO            |");
						printf("\n  |            3 - CADASTRAR UM NOVO PACIENTE                                |");
						printf("\n  |                                                                          |");
						printf("\n  |            0 - SAIR                                                      |");
						printf("\n  |                                                                          |");
						printf("\n  |                                                                          |");
						printf("\n  #--------------------------------------------------------------------------#");
						printf("\n\n  > Escolha uma opcao: ");
						scanf("%i", &option);

						switch (option)
						{
							case 1:
								{
									system("cls");
									system("cls");
									printf("\n--------------------------  CONSULTA DE PACIENTES  ----------------------------");
									printf("\n\n\n\n");

									FILE * patientList;
									patientList = fopen("listaPacientes.txt", "r");

									if (patientList == NULL)
									{
										printf(" [!] Não existem pacientes cadastrados. Pressione ENTER para continuar...");
										break;
									}

									char patients[1500];

									while (fgets(patients, 1500, patientList) != NULL)
									{
										printf("%s", patients);
									}

									fclose(patientList);
									getch();

									break;
								}
							case 2:
								{
									system("cls");
									printf("\n-----------------  CONSULTA DE PACIENTES (GRUPO DE RISCO)  --------------------");
									printf("\n\n\n\n");

									FILE * riskGroup;
									riskGroup = fopen("grupoDeRisco.txt", "r");

									if (riskGroup == NULL)
									{
										printf(" [!] Nao existem pacientes com comorbidades. Pressione ENTER para continuar...");
										break;
									}

									char comobidities[1500];

									while (fgets(comobidities, 1500, riskGroup) != NULL)
									{
										printf("%s", comobidities);
									}

									fclose(riskGroup);
									getch();

									break;
								}
							case 3:
								{
									PATIENT newPatient;
									int save = 0;
									int year = 2022;
									int age;

									do {
										char temp;

										system("cls");
										printf("\n  #--------------  CADASTRO DE PACIENTES EM CASOS DE COVID-19  --------------#");
										printf("\n  |                                                                          |");
										printf("\n  |                       CADASTRO DE NOVO PACIENTE                          |");
										printf("\n  |                                                                          |");
										printf("\n  |  NOME: ______________________________       CPF: ____________            |");
										printf("\n  |                                                                          |");
										printf("\n  |  TELEFONE: _______________       NASCIMENTO: __ / __ / ____              |");
										printf("\n  |                                                                          |");
										printf("\n  |  RUA: _____________________      N: ____    BAIRRO: ________________     |");
										printf("\n  |                                                                          |");
										printf("\n  |  CIDADE: _______________         ESTADO: __     CEP: _________           |");
										printf("\n  |                                                                          |");
										printf("\n  |  E-MAIL: ______________________________   DIAGNOSTICO: __ / __ / ____    |");
										printf("\n  |                                                                          |");
										printf("\n  |  COMORBIDADES: __________________________________________________        |");
										printf("\n  |                                                                          |");
										printf("\n  #--------------------------------------------------------------------------#");
										printf("\n\n   (Registre nos campos acima os dados do paciente)");
										printf("\n   (Caso nao haja comorbidades, deixar o campo em branco)");

										SetCursorPosition(11, 5);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.name);

										SetCursorPosition(53, 5);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.id);

										SetCursorPosition(15, 7);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.telephone);

										SetCursorPosition(49, 7);
										scanf("%i", &newPatient.birthday.day);

										SetCursorPosition(54, 7);
										scanf("%c", &temp);
										scanf("%i", &newPatient.birthday.month);

										SetCursorPosition(59, 7);
										scanf("%i", &newPatient.birthday.year);

										SetCursorPosition(10, 9);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.address.address);

										SetCursorPosition(40, 9);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.address.number);

										SetCursorPosition(56, 9);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.address.district);

										SetCursorPosition(13, 11);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.address.city);

										SetCursorPosition(45, 11);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.address.state);

										SetCursorPosition(57, 11);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.address.zipCode);

										SetCursorPosition(13, 13);
										scanf("%c", &temp);
										scanf("%[^\n]", &newPatient.email);

										SetCursorPosition(59, 13);
										scanf("%i", &newPatient.diagnosis.day);

										SetCursorPosition(64, 13);
										scanf("%c", &temp);
										scanf("%i", &newPatient.diagnosis.month);

										SetCursorPosition(69, 13);
										scanf("%i", &newPatient.diagnosis.year);

										SetCursorPosition(19, 15);
										scanf("%c", &temp);
										gets(newPatient.comorbidities);

										SetCursorPosition(1, 19);
										printf("                                                                               ");
										printf("                                                                               ");
										printf("                                                                               ");
										SetCursorPosition(1, 19);
										printf("  > Deseja salvar este cadastro? (1 = sim; 0 = nao) _");
										SetCursorPosition(53, 19);
										scanf("%i", &save);

									}

									while (save != 1);

									FILE * patientList;
									patientList = fopen("listaPacientes.txt", "a");

									fprintf(patientList, "NOME: %s\n", newPatient.name);
									fprintf(patientList, "CPF: %s\n", newPatient.id);
									fprintf(patientList, "TELEFONE: %s\n", newPatient.telephone);
									fprintf(patientList, "ENDERECO: %s, N %s\n", newPatient.address.address, newPatient.address.number);
									fprintf(patientList, "BAIRRO: %s\n", newPatient.address.district);
									fprintf(patientList, "CIDADE: %s - %s\n", newPatient.address.city, newPatient.address.state);
									fprintf(patientList, "CEP: %s\n", newPatient.address.zipCode);
									fprintf(patientList, "DATA DE NASCIMENTO: %i / %i / %i\n", newPatient.birthday.day, newPatient.birthday.month, newPatient.birthday.year);
									fprintf(patientList, "E-MAIL: %s\n", newPatient.email);
									fprintf(patientList, "DATA DO DIAGNOSTICO: %i / %i / %i\n", newPatient.diagnosis.day, newPatient.diagnosis.month, newPatient.diagnosis.year);

									if (!strcmp(newPatient.comorbidities, ""))
									{
										fprintf(patientList, "COMORBIDADES:\n\n\n");
									}
									else
									{
										fprintf(patientList, "COMORBIDADES: %s\n\n\n", newPatient.comorbidities);
									}

									age = year - newPatient.birthday.year;

									fclose(patientList);

									FILE * riskGroup;
									riskGroup = fopen("grupoDeRisco.txt", "a");

									if (age > 65 || strcmp(newPatient.comorbidities, ""))
									{
										fprintf(riskGroup, "IDADE: %i\n", age);
										fprintf(riskGroup, "CEP: %s\n\n\n", newPatient.address.zipCode);
									}

									fclose(riskGroup);

									break;
								}

							case 0:
								{
									break;
								}

							default:
								{
									printf("\n\n [!] Opcao invalida. Pressione ENTER para continuar...");
									getch();
									break;
								}
						}
					}

					while (option != 0);
					break;
				}

			case 2:
				{
					char newLogin[15];
					char newPassword[15];

					system("cls");
					printf("\n  #--------------  CADASTRO DE PACIENTES EM CASOS DE COVID-19  --------------#");
					printf("\n  |                                                                          |");
					printf("\n  |                                                                          |");
					printf("\n  |                           NOVO USUARIO                                   |");
					printf("\n  |                                                                          |");
					printf("\n  |                                                                          |");
					printf("\n  |                    INSERIR OS NOVOS DADOS DE ACESSO:                     |");
					printf("\n  |                                                                          |");
					printf("\n  |              NOVO LOGIN:                                                 |");
					printf("\n  |              NOVA SENHA:                                                 |");
					printf("\n  |                                                                          |");
					printf("\n  |                                                                          |");
					printf("\n  #--------------------------------------------------------------------------#");

					SetCursorPosition(29, 9);
					scanf("%s", &newLogin);

					SetCursorPosition(29, 10);

					int p = 0;

					do {
						newPassword[p] = getch();

						if (newPassword[p] != '\r' && newPassword[p] != '\b')
						{
							printf("*");
						}

						if (newPassword[p] == '\b' && p >= 1)
						{
							p -= 2;
							SetCursorPosition(29 + p, 10);
							printf(" ");
							SetCursorPosition(29 + p, 10);
						}

						p++;

					}

					while (newPassword[p - 1] != '\r');

					newPassword[p - 1] = '\0';

					SetCursorPosition(0, 20);

					FILE * users;
					users = fopen("users.txt", "r");
					char user[15];
					int saveUser = 1;
					while (fgets(user, sizeof(user), users) != NULL)
					{
						if (strstr(user, newLogin) != NULL)
						{
							saveUser = 0;
							printf(" [!] Usuario ja cadastrado. Pressione ENTER para continuar...");
							getch();
						}
					}

					fclose(users);

					if (saveUser == 1)
					{
						FILE * users;
						users = fopen("users.txt", "a");
						fprintf(users, "%s\n", newLogin);
						fprintf(users, "%s\n", newPassword);
						fclose(users);

						printf("  > Usuario criado com sucesso. Pressione ENTER para continuar...");
						getch();
					}

					break;
				}

			case 0:
				{
					break;
				}

			default:
				{
					printf("\n\n [!] Opcao invalida. Pressione ENTER para continuar...");
					getch();
					break;
				}
		}
	}

	while (option != 0);

	SetConsoleCP(cpin);
	SetConsoleOutputCP(cpout);

	return 0;
}
