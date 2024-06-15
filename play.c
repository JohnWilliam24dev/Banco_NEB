#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
int main(){
insert_client_natural_person("Joao Silva", "SeNhA123", "1234", "01/01/1980", "12345678901", "(11) 91234-5678", "Rua A, 123", 1000.00, 5000.00);
insert_client_natural_person("Maria Oliveira", "PaSsWoRd456", "5678", "02/02/1990", "23456789012", "(21) 92345-6789", "Avenida B, 456", 2000.00, 10000.00);
insert_client_natural_person("Carlos Pereira", "AbCdEf789", "9101", "03/03/1975", "34567890123", "(31) 93456-7890", "Praca C, 789", 3000.00, 15000.00);
insert_client_natural_person("Ana Costa", "XyZaBc123", "1122", "04/04/1985", "45678901234", "(41) 94567-8901", "Rua D, 101", 4000.00, 20000.00);
insert_client_natural_person("Paulo Santos", "NoPaSsWoRd", "3344", "05/05/1995", "56789012345", "(51) 95678-9012", "Avenida E, 202", 5000.00, 25000.00);
insert_client_natural_person("Fernanda Lima", "SeNhA321", "5566", "06/06/2000", "67890123456", "(61) 96789-0123", "Estrada F, 303", 6000.00, 30000.00);
insert_client_natural_person("Lucas Rocha", "MyPaSsWoRd", "7788", "07/07/1987", "78901234567", "(71) 97890-1234", "Rua G, 404", 7000.00, 35000.00);
insert_client_natural_person("Juliana Almeida", "LoGiN123", "9900", "08/08/1992", "89012345678", "(81) 08901-2345", "Avenida H, 505", 8000.00, 40000.00);
insert_client_natural_person("Marcos Fernandes", "123PaSs", "1010", "09/09/1983", "90123456789", "(91) 19012-3456", "Rua I, 606", 9000.00, 45000.00);
insert_client_natural_person("Sofia Castro", "PaSs999", "1111", "10/10/1978", "01234567890", "(92) 29123-4567", "Avenida J, 707", 10000.00, 50000.00);
insert_client_natural_person("Rafael Moreira", "PaSsWoRd321", "1212", "11/11/1991", "12345678011", "(93) 39234-5678", "Rua K, 808", 11000.00, 55000.00);
insert_client_natural_person("Larissa Martins", "1PaSs1", "1313", "12/12/1984", "23456789013", "(94) 49345-6789", "Avenida L, 909", 12000.00, 60000.00);
insert_client_natural_person("Gustavo Barbosa", "SeNhA456", "1414", "13/01/1993", "34567890124", "(95) 59456-7890", "Rua M, 1010", 13000.00, 65000.00);
insert_client_natural_person("Mariana Ribeiro", "2PaSs2", "1515", "14/02/1986", "45678901235", "(96) 69567-8901", "Praca N, 1111", 14000.00, 70000.00);
insert_client_natural_person("Fabio Mendes", "MyLoGiN", "1616", "15/03/1979", "56789012346", "(97) 79678-9012", "Avenida O, 1212", 15000.00, 75000.00);
insert_client_natural_person("Beatriz Carvalho", "3PaSs3", "1717", "16/04/1988", "67890123457", "(98) 89789-0123", "Rua P, 1313", 16000.00, 80000.00);
insert_client_natural_person("Diego Teixeira", "SenHa789", "1818", "17/05/1990", "78901234568", "(99) 99890-1234", "Avenida Q, 1414", 17000.00, 85000.00);
insert_client_natural_person("Alice Correia", "4PaSs4", "1919", "18/06/1982", "89012345679", "(11) 09901-2345", "Estrada R, 1515", 18000.00, 90000.00);
insert_client_natural_person("Rodrigo Nunes", "MyPaSs456", "2020", "19/07/1994", "90123456780", "(21) 10012-3456", "Rua S, 1616", 19000.00, 95000.00);
insert_client_natural_person("Camila Azevedo", "5PaSs5", "2121", "20/08/1981", "01234567891", "(31) 20123-4567", "Avenida T, 1717", 20000.00, 100000.00);
insert_client_natural_person("Eduardo Lima", "PaSs000", "2222", "21/09/1989", "12345678912", "(41) 30234-5678", "Rua U, 1818", 21000.00, 105000.00);
insert_client_natural_person("Aline Souza", "6PaSs6", "2323", "22/10/1992", "23456789014", "(51) 40345-6789", "Estrada V, 1919", 22000.00, 110000.00);
insert_client_natural_person("Bruno Carvalho", "PaSsWoRd001", "2424", "23/11/1985", "34567890125", "(61) 50456-7890", "Avenida W, 2020", 23000.00, 115000.00);
insert_client_natural_person("Patricia Gomes", "7PaSs7", "2525", "24/12/1993", "45678901236", "(71) 60567-8901", "Rua X, 2121", 24000.00, 120000.00);
insert_client_natural_person("Renato Oliveira", "8PaSs8", "2626", "25/01/1987", "56789012347", "(81) 70678-9012", "Avenida Y, 2222", 25000.00, 125000.00);
insert_client_natural_person("Leticia Rodrigues", "MyPaSs123", "2727", "26/02/1983", "67890123458", "(91) 80789-0123", "Rua Z, 2323", 26000.00, 130000.00);
insert_client_natural_person("Thiago Martins", "9PaSs9", "2828", "27/03/1991", "78901234569", "(92) 90890-1234", "Avenida AA, 2424", 27000.00, 135000.00);
insert_client_natural_person("Isabela Alves", "0PaSs0", "2929", "28/04/1984", "89012345680", "(93) 01901-2345", "Rua BB, 2525", 28000.00, 140000.00);
	}