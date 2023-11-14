// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "LinkedList.h"
#include "func.h"

template <typename T>
class LinkedList;
class matrix;


int main() {/*
    LinkedList<matrix> list;
    matrix matrix_my;
    matrix_my.create_matrix();
    list.add(matrix_my);
    std::cout << list;
    matrix_my.create_matrix();
    list.add(matrix_my);
    std::cout << list;
    matrix_my.create_matrix();
    list.add(matrix_my);


   std::cout << find_index(list, list.get(2)) << std::endl;
    std::cout << find_index(list, list.get(1)) << std::endl;
    std::cout << find_index(list, list.get(0)) << std::endl;

/*
    matrix temp_matr = all_choise(list);
    int temp_index = find_index(list, temp_matr);
    temp_matr = (temp_matr + all_choise(list));
    list.get(temp_index - 1) = temp_matr;

    std::cout << list;
*/   LinkedList<matrix> list;

    matrix matrix_my;
    list.add(matrix_my);

    int func_choize;
    int num_of_matrix = 0;
    while (true) {
        func_choize = menu();

        switch (func_choize) {
            case 0: {
                logFile.close();
                return 0;
            }
            case 1: {//умничка
                if (num_of_matrix == 0) {
                    list.get(0).create_matrix();
                    num_of_matrix++;
                } else {
//                    if (whot_create_matrix(0) == 0) {
                        matrix temp;
                        temp.create_matrix();
                        list.add(temp);
/*                    } else {
                        matrix temp;
                        temp = choise(list);
                        list.add(temp);
                    }*/
                    num_of_matrix++;
                    break;
                }
                break;
            }
            case 2: {//нормас
                std::cout << list;
                break;
            }
            case 3: {//крут
                all_choise(list).create_matrix();
                break;
            }
            case 4: {//не так и муторно
              //  all_choise(list).transposing_matrix();
                matrix mat_to_transpose = all_choise(list);
                int temp_index = find_index(list, mat_to_transpose);
              //  std::cout << temp_index;
                mat_to_transpose.transposing_matrix();
                list.get(temp_index) = mat_to_transpose;
                    break;
            }
            case 5: {//+
                matrix temp_matr = all_choise(list);
                int temp_index = find_index(list, temp_matr);
                temp_matr = (temp_matr + all_choise(list));
                list.get(temp_index) = temp_matr;
                break;
            }
            case 6: {//-
                matrix temp_matr = all_choise(list);
                int temp_index = find_index(list, temp_matr);
                temp_matr = (temp_matr - all_choise(list));
                list.get(temp_index) = temp_matr;
                break;
            }
            case 7: {//+=
                matrix temp_matr = all_choise(list);
                int temp_index = find_index(list, temp_matr);
                int N = whot_create_matrix(9);
                temp_matr += N;
                list.get(temp_index) = temp_matr;
                break;
            }
            case 8: {//-=
                matrix temp_matr = all_choise(list);
                int temp_index = find_index(list, temp_matr);
                int N = whot_create_matrix(9);
                temp_matr -= N;
                list.get(temp_index) = temp_matr;
                break;
            }
            case 9: {//*=
                matrix temp_matr = all_choise(list);
                int temp_index = find_index(list, temp_matr);
                int N = whot_create_matrix(9);
                temp_matr *= N;
                list.get(temp_index) = temp_matr;
                break;
            }
            case 10: {//<>
                switch (all_choise(list) == all_choise(list)) {
                    case 1:{
                        std::cout << "The first element of the first matrix is larger than the corresponding element of the second matrix, >\n";
                        break;
                    }
                    case 0:{
                        std::cout << "The first element of the first matrix is equal to the corresponding element of the second matrix, = \n";
                        break;
                    }
                    case -1:{
                        std::cout << "The first element of the first matrix is smaller than the corresponding element of the second matrix, <\n";
                        break;
                    }
                }

                break;
            }

        }
    }
/**/
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

