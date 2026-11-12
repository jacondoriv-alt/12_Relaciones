#include <iostream>
#include <string>
using namespace std;

class Display {
private:
    string tipo;

public:
    Display(string tipo) {
        this->tipo = tipo;
    }

    string getTipo() {
        return tipo;
    }
};

class Hora {
private:
    int hora;
    int minutos;
    int segundos;

public:
    Hora(int h, int m, int s) {
        hora = h;
        minutos = m;
        segundos = s;
    }

    int getHora() {
        return hora;
    }

    int getMinutos() {
        return minutos;
    }

    int getSegundos() {
        return segundos;
    }
};

class Reloj {
private:
    Display* pDisplay;
    Hora pHora;

public:
    Reloj(int h, int m, int s) : pHora(h, m, s) {
        pDisplay = NULL;
    }

    void asignarDisplay(Display* pD) {
        pDisplay = pD;
    }

    void mostrarReloj() {
        if (pDisplay == NULL) {
            cout << "No hay display asignado" << endl;
            return;
        }

        if (pDisplay->getTipo() == "digital") {
            cout << "[" << pHora.getHora() << ":";
            cout << pHora.getMinutos() << ":";
            cout << pHora.getSegundos() << "]" << endl;
        }
        else {
            cout << "-->" << pHora.getHora() << ":";
            cout << pHora.getMinutos() << ":";
            cout << pHora.getSegundos() << "<--" << endl;
        }
    }
};

int main() {
    Display digital("digital");
    Display analogico("analogico");

    Reloj reloj1(10, 15, 55);
    Reloj reloj2(10, 15, 55);

    reloj1.asignarDisplay(&digital);
    reloj2.asignarDisplay(&analogico);

    reloj1.mostrarReloj();
    reloj2.mostrarReloj();

    return 0;
}

