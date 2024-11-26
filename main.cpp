#include <iostream>
#include <cstdlib>
using namespace std;

int* resize_dobro(int* lista, int& capacidade_atual) {

    capacidade_atual *= 2;
    int* nova_lista = new int[capacidade_atual];

    for (int i = 0; i < capacidade_atual / 2; i++) {
        nova_lista[i] = lista[i];
    }

    nova_lista = lista;

    delete[] lista;
    return nova_lista;
}

int* resize_metade(int* lista, int& capacidade_atual) {

    capacidade_atual /= 2;
    int* nova_lista = new int[capacidade_atual];

    for (int i = 0; i < capacidade_atual; i++) {
        nova_lista[i] = lista[i];
    }

    nova_lista = lista;

    delete[] lista;
    return nova_lista;
}

int main() {
    int capacidade_atual = 50, tamanho_atual = 0, cell;
    int* lista = new int[capacidade_atual];
    string choice;

    cout << "Deseja\n(1) Adicionar elementos;\n(2) Remover elementos." << endl;
    cout << "Escolha: ";
    cin >> cell;
    
    if (cell == 1) {
        while (true) {
            for (int i = 0; i < 50; i++) {
                lista[tamanho_atual] = tamanho_atual + 1;
                tamanho_atual++;
            }
            for (int i = 0; i < tamanho_atual; i++) {
                cout << i + 1 << "° elemento: " << lista[i] << endl;
            }
            cout << "Deseja continuar adicionando elementos? " << endl;
            cin >> choice;

            if (choice == "sim") {
                for (int i = tamanho_atual; i < capacidade_atual; i++) {
                    lista[tamanho_atual] = tamanho_atual + 1;
                    tamanho_atual++;
                }
            }
        }

    } else if (cell == 2) {

        for (int i = 0; i < 10; i++) {
            lista[i] = i + 1;
            tamanho_atual++;
        }

        cout << "Lista inicial para remocao de elementos:" << endl;
        for (int i = 0; i < tamanho_atual; i++) {
            cout << i + 1 << "° elemento: " << lista[i] << endl;
        }

        while (tamanho_atual > 0) {
            tamanho_atual--;

            if (tamanho_atual <= capacidade_atual / 4) {
                lista = resize_metade(lista, capacidade_atual);
            }
        }

        cout << "Lista após remoção automática de elementos:" << endl;
        for (int i = 0; i < tamanho_atual; i++) {
            cout << i + 1 << "° elemento: " << lista[i] << endl;
        }
    } else {
        cout << "Digite uma opcao valida!" << endl;
    }

    delete[] lista;

    return 0;

}
