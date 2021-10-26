#include <iostream>
#include <time.h>
#include <string>
using namespace std;

const bool MODODEBUG = false;
const int LIM_INF_HAB = 1, LIM_SUP_HAB = 2;
const int LIM_INF_VEL = 1, LIM_SUP_VEL = 3;
const int ANCHOPISTA = 7;
//nunca puede haber variables a nivel global, en cambio las constantes si


int modoJuego(int n_modoJuego); //revisar
int golpeoBola(int posicionTenista, int habilidad);
int correTenista(int poicionTenista, int velocidad, int posicionBola);

void introducirDato();
string jugador1, jugador2;
int velocidad1, velocidad2, habilidad1, habilidad2, posicionTenista1, posicionTenista2, posicionBola, turno, turnoFijo, gameGolpeo = 0, gameCorre = 0, set = 0;

string marcadorString[] = { "0", "0", "1", "5", "3", "0", "4", "0", "A", "d" };
void marcador(int puntuacion1, int puntuacion2);
int puntuacion1 = 0, puntuacion2 = 0;

int main() {

	introducirDato();

	cout << "El ancho de la pista es de " << ANCHOPISTA << " calles" << endl;

	turnoFijo = rand() % 2 + 1;
	turno = turnoFijo;
	if (turno == 1)
	{
		cout << "Comienza sacando " << jugador1 << endl;
		if (MODODEBUG)
			cout << jugador1 << " en casilla 3 y " << jugador2 << " en casilla 3" << endl;
	}
	else
	{
		cout << "Comienza sacando " << jugador2 << endl;
		if (MODODEBUG)
			cout << jugador1 << " en casilla 3 y " << jugador2 << " en casilla 3" << endl;
	}
	while (set == 0) {

		posicionTenista1 = (ANCHOPISTA + 1) / 2;
		posicionTenista2 = (ANCHOPISTA + 1) / 2;

		posicionBola = (ANCHOPISTA + 1) / 2;

		gameGolpeo = 0;
		gameCorre = 0;

		turno = turnoFijo;

		while (gameGolpeo == 0 && gameCorre == 0) {
			while (gameGolpeo == 0 && gameCorre == 0) {
				switch (turno) {
				case 1:
					posicionBola = golpeoBola(posicionTenista1, habilidad1);

					if (posicionBola < 1 || posicionBola > ANCHOPISTA) {
						cout << "Punto para " << jugador2 << endl;

						gameCorre = 1;
						if (MODODEBUG)
							cout<<
					}

					else {
						cout << "Golpea " << jugador1 << endl; //modo Debug
						turno++;
					}
					break;
				case 2:
					posicionBola = golpeoBola(posicionTenista2, habilidad2);

					if (posicionBola < 1 || posicionBola > ANCHOPISTA) {
						cout << "Punto para " << jugador1 << endl;

						gameCorre = 1;
					}

					else {
						cout << "Golpea " << jugador2 << endl;
						turno--;
					}
					break;
				}

				if (posicionBola < 1 || posicionBola > ANCHOPISTA) {

					if (turno == 1) {
						puntuacion2++;
					}
					else {
						puntuacion1++;
					}

					marcador(puntuacion1, puntuacion2);

					system("pause");

				}

				gameGolpeo = 1;
			}

			gameGolpeo = 0;

			while (gameGolpeo == 0 && gameCorre == 0) {
				switch (turno) {
				case 1:
					posicionTenista1 = correTenista(posicionTenista1, velocidad1, posicionBola);

					if (posicionTenista1 != posicionBola) {
						cout << "Punto para " << jugador2 << endl;

						puntuacion2++;
						marcador(puntuacion1, puntuacion2);

						gameGolpeo = 1;

						system("pause");

					}

					break;
				case 2:
					posicionTenista2 = correTenista(posicionTenista2, velocidad2, posicionBola);

					if (posicionTenista2 != posicionBola) {
						cout << "Punto para " << jugador1 << endl;

						puntuacion1++;
						marcador(puntuacion1, puntuacion2);

						gameGolpeo = 1;

						system("pause");

					}

					break;
				}

				gameCorre = 1;
			}

			gameCorre = 0;
		}
	}
}



void introducirDato() {
	cout << "Jugador 1, introduzca sus iniciales: ";
	cin >> jugador1;

	cout << "Introduzca su habilidad, un valor entre " << LIM_INF_HAB << " y " << LIM_SUP_HAB << ": ";
	cin >> habilidad1;
	while (habilidad1 < LIM_INF_HAB || habilidad1 > LIM_SUP_HAB) {
		cout << "Ha introducido un valor fuera del rango permitido" << endl;
		cout << "Introduzca su habilidad, un valor entre " << LIM_INF_HAB << " y " << LIM_SUP_HAB << ": ";
		cin >> habilidad1;
	}

	cout << "Introduzca su velocidad, un valor entre " << LIM_INF_VEL << " y " << LIM_SUP_VEL << ": ";
	cin >> velocidad1;
	while (velocidad1 < LIM_INF_VEL || velocidad1 > LIM_SUP_VEL) {
		cout << "Ha introducido un valor fuera del rango permitido" << endl;
		cout << "Introduzca su habilidad, un valor entre " << LIM_INF_VEL << " y " << LIM_SUP_VEL << ": ";
		cin >> velocidad1;
	}


	cout << "Jugador 2, introduzca sus iniciales: ";
	cin >> jugador2;

	cout << "Introduzca su habilidad, un valor entre " << LIM_INF_HAB << " y " << LIM_SUP_HAB << ": ";
	cin >> habilidad2;
	while (habilidad2 < LIM_INF_HAB || habilidad2 > LIM_SUP_HAB) {
		cout << "Ha introducido un valor fuera del rango permitido" << endl;
		cout << "Introduzca su habilidad, un valor entre " << LIM_INF_HAB << " y " << LIM_SUP_HAB << ": ";
		cin >> habilidad2;
	}

	cout << "Introduzca su velocidad, un valor entre " << LIM_INF_VEL << " y " << LIM_SUP_VEL << ": ";
	cin >> velocidad2;
	while (velocidad2 < LIM_INF_VEL || velocidad2 > LIM_SUP_VEL) {
		cout << "Ha introducido un valor fuera del rango permitido" << endl;
		cout << "Introduzca su habilidad, un valor entre " << LIM_INF_VEL << " y " << LIM_SUP_VEL << ": ";
		cin >> velocidad2;
	}
}


int modoJuego(int n_modoJuego) { //revisar
	cout << "Elige el modo de juego" << endl;
	cout << "0: Manual" << endl;
	cout << "1: Automatico" << endl;

	cin >> n_modoJuego;

	return n_modoJuego;
}



int correTenista(int posicionTenista, int velocidad, int posicionBola)
{
	int distanciaBola;
	distanciaBola = abs(posicionBola - posicionTenista);
	//poner en valor absoluto, asi el primer if no haria falta



	if (velocidad >= distanciaBola)
	{
		posicionTenista = posicionBola;
		if (MODODEBUG) //es lo mismo que preguntar si modoDebug==True
			cout << "El tenista alcanza a la bola para golpearla" << endl;
	}
	if (velocidad <= distanciaBola) {
		posicionTenista = posicionTenista + velocidad;
		if (MODODEBUG)
			cout << "El tenista no llega a la bola" << endl;
	}
	return posicionTenista;
}


int golpeoBola(int posicionTenista, int habilidad) {
	int destino, probabilidad, res_lanzamiento, lado;
	unsigned int distancia;

	cout << "Introducir destino deseado: ";
	cin >> destino;
	

	while (destino < 1 || destino > ANCHOPISTA) {
		cout << "Valor introducido no valido" << endl;
		cout << "Velva a introducir el destino: ";
		cin >> destino;

	}

	distancia = destino - posicionTenista;

	if (distancia < habilidad)
	{
		res_lanzamiento = destino;
		if (MODODEBUG)
		{
			cout << "Ha sido un tiro sencillo." << endl;
			cout << "La bola llega a la casilla " << res_lanzamiento << endl;
		}
	}
		


	else {
		probabilidad = 100 - ((distancia - habilidad) / ((ANCHOPISTA - 1) - LIM_INF_HAB)) * 100;
		res_lanzamiento = rand() % 100;

		if (res_lanzamiento < probabilidad)
		{ 
			res_lanzamiento = destino;
			if (MODODEBUG)
			{
				cout << "Ese ha sido un tiro complicado. " << endl;
				cout << "La pelota llega a la casilla " << res_lanzamiento < endl;
			}
				
		}
			res_lanzamiento = destino;

		else { //no coge variables
			lado = rand() % 2;

			if (lado == 0)
				res_lanzamiento = destino + 1;

			else
				res_lanzamiento = destino - 1;
			if (MODODEBUG)
			{
				cout << "Ese ha sido un tiro con gran dificultad."<<endl:
				cout << "El destino de la bola es " << res_lanzamiento << endl;
			}
				
		}
	}

	return res_lanzamiento;
}

void marcador(int puntuacion1, int puntuacion2) {
	if (puntuacion1 == 3 && puntuacion2 == 4) {
		cout << jugador1 << "   " << marcadorString[2 * puntuacion1] << marcadorString[2 * puntuacion1 + 1] << " - " << marcadorString[8] << marcadorString[9] << "   " << jugador2 << endl;
	}

	else if (puntuacion1 == 4 && puntuacion2 == 3) {
		cout << jugador1 << "   " << marcadorString[8] << marcadorString[9] << " - " << marcadorString[2 * puntuacion2] << marcadorString[2 * puntuacion2 + 1] << "   " << jugador2 << endl;
	}

	else if (puntuacion1 == 4 && puntuacion2 == 4) {
		puntuacion1 = 3;
		puntuacion2 = 3;

		cout << jugador1 << "   " << marcadorString[2 * puntuacion1] << marcadorString[2 * puntuacion1 + 1] << " - " << marcadorString[2 * puntuacion2] << marcadorString[2 * puntuacion2 + 1] << "   " << jugador2 << endl;
	}

	else if (puntuacion1 == 5) {
		cout << "Gana el jugador " << jugador1 << endl;
		set = 1;
	}
	else if (puntuacion1 == 4 && puntuacion2 != 3) {
		cout << "Gana el jugador " << jugador1 << endl;
		set = 1;
	}
	else if (puntuacion2 == 5) {
		cout << "Gana el jugador " << jugador2 << endl;
		set = 1;
	}
	else if (puntuacion2 == 4 && puntuacion1 != 3) {
		cout << "Gana el jugador " << jugador2 << endl;
		set = 1;
	}

	else
		cout << jugador1 << "   " << marcadorString[2 * puntuacion1] << marcadorString[2 * puntuacion1 + 1] << " - " << marcadorString[2 * puntuacion2] << marcadorString[2 * puntuacion2 + 1] << "   " << jugador2 << endl;
}






