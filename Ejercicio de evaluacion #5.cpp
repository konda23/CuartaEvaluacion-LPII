#include <iostream>
using namespace std;

int main() {
    
    float TASA_$_A_BS = 607.39; 
    float TASA_BS_A_EUR = 697.36; 
    int opcion=0;
    float dolares=0;
    float bolivares=0;
    float euros=0;
    char repetir;
    float meta=0;
    float salario=0;
    float gastos=0;
    float ahorromensual=0;
    float meses=0;
    float pesoactual=0;
    float pesodeseado=0;
    float kg_por_mes=0;
    float kg_a_perder=0;
    float meses_peso=0;
    
    
    do {
        system("cls");
        
        cout << "==================== MENU DE OPCIONES ====================" << endl;
        cout << "1. Convertir $ a Bs" << endl;
        cout << "2. Convertir Bs a euros" << endl;
        cout << "3. Calcular tiempo para meta de ahorro" << endl;
        cout << "4. Calcular tiempo para alcanzar peso deseado" << endl;
        cout << "========================================================" << endl;
        cout << "Seleccione una opcion (1-4): ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "--- Convertir $ a Bs ---" << endl;
                cout << "Ingrese la cantidad en dolares ($): ";
                cin >> dolares;
                
                bolivares = dolares * TASA_$_A_BS;
                cout << "Resultado: " << dolares << " $ equivalen a " << bolivares << " Bs." << endl;
                break;
            }
            case 2: {
                cout << "--- Convertir Bs a Euros ---" << endl;
                cout << "Ingrese la cantidad en Bolivares (Bs): ";
                cin >> bolivares;
                
                euros = bolivares / TASA_BS_A_EUR;
                cout << "Resultado: " << bolivares << " Bs equivalen a " << euros << " EUR." << endl;
                break;
            }
            case 3: {
                cout << "--- Calcular Tiempo de Ahorro ---" << endl;
                cout << "Ingrese la meta monetaria a alcanzar: ";
                cin >> meta;
                cout << "Ingrese su salario mensual base: ";
                cin >> salario;
                cout << "Ingrese sus gastos mensuales fijos: ";
                cin >> gastos;

                ahorromensual = salario - gastos;

                if (ahorromensual <= 0) {
                    cout << "Error: Tus gastos son mayores o iguales a tus ingresos. No es posible ahorrar." << endl;
                } else {
                     meses = meta / ahorromensual;
                    cout << "Necesitara ahorrar durante " << meses << " meses para alcanzar la meta." << endl;
                }
                break;
            }
            case 4: {
                cout << "--- Calcular Tiempo para Peso Deseado ---" << endl;
                cout << "Ingrese su peso actual (kg): ";
                cin >> pesoactual;
                cout << "Ingrese su peso deseado (kg): ";
                cin >> pesodeseado;
                cout << "Ingrese los kg que es capaz de comprometerse a perder por mes: ";
                cin >> kg_por_mes;

                if (pesodeseado >= pesoactual) {
                    cout << "El peso deseado debe ser menor que el peso actual para calcular la perdida." << endl;
                } else if (kg_por_mes <= 0) {
                    cout << "Error: El compromiso de perdida mensual debe ser mayor a 0 kg." << endl;
                } else {
                    kg_a_perder = pesoactual - pesodeseado;
                     meses_peso = kg_a_perder / kg_por_mes;
                    cout << "Tardara: " << meses_peso << " meses en alcanzar su peso deseado." << endl;
                }
                break;
            }
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }

        
        cout << "Desea realizar otra operacion? (S/N): "<<endl;
        cout << "si...Marque S "<<endl;
        cout << "no...Marque N "<<endl;
        cin >> repetir;

    } while (repetir == 'S' || repetir == 's');

    cout << "  Programa finalizado " << endl;
    return 0;
}
