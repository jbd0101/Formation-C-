#include <iostream>

using namespace std;

int main()
{
    int a;
    unsigned int d;
    float f,g;
    double h,i;
    bool j,k;
    char l; // déclaration de la chaîne de caractère
    int m; // déclaration du nombre

    // calcul avec un nombre entier

    cout << " valeur de l'entier: ";cin >> a;
    cout << "l'inverse de " << a << " = " << 1/a << endl;

    //Calcul avec un entier non signé

    cout << " valeur de l'entier non signe : ";cin >> d;
    cout << "l'inverse de " << d << " = " << 1/d << endl;

    //calcul avec un nombre décimal de type float

    cout << " valeur du nombre decimal est "; cin >> f;
    g = 1/f;
    cout << "l'inverse de " << f << " est " << g << endl;

    // calcul avec un nombre décimal de type double

     cout << " valeur du nombre decimal est "; cin >> h;
    i = 1/h;
    cout << "l'inverse de " << h << " est " << i << endl;

    // Affichage de l'état du type boléen

    cout << " valeur 0 ou 1 de la boleenne: ";cin >> j;
    cout << boolalpha << j << endl;                         // affiche true ou false
    cout << noboolalpha << j << endl;                       // affiche la valeur de cet état
    k =! j;
    cout << " valeur 0 ou 1 de l'etat contraire de la valeur boleenne precedente: \n";
    cout << boolalpha << k << endl;                         // affiche true ou false
    cout << noboolalpha << k << endl;                       // affiche la valeur de cet état

     // Affichage du code ASCII d'un caractère et réciproquement

    cout << " un caractere : "; cin >> l;
    cout << " le code ASCII corespondant est : " << (int)l << endl;                //code ASCII
    cout << " un entier entre 0 et 127: ";cin>>m;                                  // donne code ASCII
    cout << " le caractere correspondant à ce nombre est : " << (char)m << endl;   // donne le charactère


    return 0;
}
