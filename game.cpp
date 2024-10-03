#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

char board[3][3];
char currentPlayer;

void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << ' ';
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << endl;
        if (i < 2) cout << "  -----\n";
    }
}

bool isWinner(char player) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int escolhajogo;
    bool executando = true;

    while (executando) {
        cout << "================" << endl;
        cout << "Escolha o jogo: " << endl;
        cout << "1. JOGO DA VELHA" << endl;
        cout << "2. Jogo 2" << endl;
        cout << "3. Sair" << endl;
        cout << "================" << endl;

        while (true) {
            cout << "Digite sua escolha: ";
            cin >> escolhajogo;

            if (cin.fail() || escolhajogo < 1 || escolhajogo > 3) {
                cout << "Opção inválida! Tente novamente." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        switch (escolhajogo) {
            case 1: {
                cout << endl;
                cout << "* JOGO DA VELHA *" << endl;
                int escolhamodo;

                cout << "=======================" << endl;
                cout << "Escolha o modo de jogo: " << endl;
                cout << "1. PvP" << endl;
                cout << "2. PvBot" << endl;
                cout << "3. BotvBot" << endl;
                cout << "4. Sair" << endl;
                cout << "=====================" << endl;

                while (true) {
                    cout << "Digite sua escolha: ";
                    cin >> escolhamodo;

                    if (cin.fail() || escolhamodo < 1 || escolhamodo > 4) {
                        cout << "Opção inválida! Tente novamente." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }

                switch (escolhamodo) {
                    case 1: {
                        cout << endl;
                        cout << "* Escolheu PvP *\n" << endl;

                        initBoard();
                    	currentPlayer = 'X';
                    	int row, col;
                    	
                    	while (true) {
                    		printBoard();
                    		cout << "\nJogador " << currentPlayer << ", escolha a linha e a coluna (0-2): ";
                    		
                    		if (!(cin >> row >> col) || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                    			cout << "\nJogada inválida, tente novamente.\n" << endl;
                    			cin.clear();
                    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    			continue;
                    		}
                    		
                    		cout << endl;
                    		board[row][col] = currentPlayer;
                    		
                    		if (isWinner(currentPlayer)) {
                    			printBoard();
                    			cout << "\nParabéns! Jogador " << currentPlayer << " venceu!" << endl;
                    			break;
                    		}
                    		
                    		if (isDraw()) {
                    			printBoard();
                    			cout << "Empate!" << endl;
                    			break;
                    		}
                    		
                    		switchPlayer();
                    	}
                        break;
                    }
                    case 2:
                    case 3:
                        cout << "Modo ainda não implementado!" << endl;
                        break;
                    case 4:
                        executando = false;
                        break;
                }
                break;
            }
            case 2:
          
            case 3:
                executando = false;
                break;
        }
    }

    return 0;
}