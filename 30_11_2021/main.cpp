/*
Do pobrania jest plik main.cpp, którego nie wolno modyfikować*. Państwa zadaniem jest utworzenie stosownych plików oraz implantacja kodu w języku C++, tak, aby wywołanie programu prowadziło do wypisania na ekran treści w pełni spójnej (modulo adresy pamięci) z tą zawartą w komentarzu na końcu pliku main.cpp. Zadanie weryfikuje znajomość typów, tablic, instrukcji sterujących, pętli, struktur, funkcji, wskaźników, rekurencji, obsługi wyjścia.

* - do weryfikacji poprawności Państwa programu zostanie użyta oryginalna wersja main.cpp. W celach roboczych (w trakcie pracy nad programem) dopuszcza się dowolną modyfikację pliku main.cpp.
//////////////////////////////////
Celem zadania jest przećwiczenie konstruktorów a także funkcji i zmiennych statycznych

Wektor można przedstawić np. we współrzędnych biegunowych lub kartezjańskich. Jednakże konstruktor z dwoma argumentami double byłby niejednoznaczny:
Vector2D(double x, double y);
Vector2D(double r, double phi); // żle!
Można użyć tzw. named constructor idiom, tj. stworzyć funkcje zwracające obiekt:
- fromCarthesian(double x, double y);
- fromPolar(double r, double phi);

Proszę napisać klasę Vector2D, reprezentującą wektor. Ma on 2 współrzędne i metody:
- add, wylicza sumę dwóch wektorów,
- dot, wylicza iloczyn skalarny,
- print do wypisania wektora,
- oraz zwracające obiekt Vector2D na podstawie współrzędnych
Ponadto możliwe jest zliczanie obiektów klasy.

Wymagane utworzenie konstruktora przenoszącego.
//////////////////////////////////
Nazwa pliku wykonywalnego: Lab09

Ostateczny program powinien być przyjazny dla programisty (mieć czytelny i dobrze napisany kod ze stosownymi komentarzami). Pełne rozwiązanie należy wysłać (w formacie archiwum zip o ustalonej nazwie) do serwisu UPeL przed końcem zajęć.
*/
#include <iostream>
#include "include/Vector2D.h"

int main() {
	{
		Vector2D v1 = Vector2D::fromCarthesian(2., 3.);		// (x, y)
		const Vector2D v2 = Vector2D::fromPolar(4., 30.);	// (promień, kąt w stopniach)

		v1.print("v1: ");
		v2.print("v2: ");
		std::cout << "==== START: Number of Vector2Ds: " << Vector2D::count << std::endl;

		double prod = v1.dot(v2);
		std::cout << "Dot product = " << prod << std::endl;
		
		const Vector2D v3 = v1.add(v2); 
		v3.print("v3: ");
		std::cout << v3.dot(v1) << ", " << v3.dot(v2) << std::endl;

		Vector2D v4 = v2;
		v4.print("v4: ");
		std::cout << "==== MIDDLE: Number of Vector2Ds: " << Vector2D::count << std::endl;

		Vector2D v5 (std::move(v3.add(v1)));
		v5.print("v5: ");
	}
	std::cout << "==== END: Number of Vector2Ds: " << Vector2D::count << std::endl;
}
/* //Output:

v1: (2, 3)
v2: (3.4641, 2)
==== START: Number of Vector2Ds: 2
Dot product = 12.9282
v3: (5.4641, 5)
25.9282, 28.9282
copying (3.4641, 2)
v4: (3.4641, 2)
==== MIDDLE: Number of Vector2Ds: 4
moving (7.4641, 8)
v5: (7.4641, 8)
==== END: Number of Vector2Ds: 0
*/