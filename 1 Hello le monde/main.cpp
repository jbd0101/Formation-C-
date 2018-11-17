#include <iostream>         // librairie Input/Output Stream

using namespace std;        // espace de noms standard


int main()
{
    /*
        cout affiche un message sur la console
        cin  entre des informations dans le programme
        */
//  cout << "Hello le monde" << endl;       // endl : retour à la ligne
//  cout << "Hello le monde" << "\n";       //  "\n" : retour à la ligne
    cout << "Hello le monde \n";            // "....  \n" : retour à la ligne
    cout << "\n";                           // retour à la ligne
//  cout << "Hello le monde" << endl << "Hello le monde \n";

    int a;

    cout << "donner un nombre a " << "\n" ;

    cin >> a;

    cout << "le double de a vaut " << 2*a;

    return 0;                               // termine la fonction
}
