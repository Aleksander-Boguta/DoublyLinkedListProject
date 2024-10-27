Celem zadania jest zaimplementowanie struktury danych nazywanej listą dwukierunkową (ang. doubly linked list), która jest jedną z podstawowych liniowych struktur danych. Lista dwukierunkowa składa się z węzłów, gdzie każdy węzeł zawiera trzy informacje:

Dane właściwe (rekord lub obiekt),
Wskaźnik na poprzedni element,
Wskaźnik na następny element.
Lista będzie przechowywać wskaźniki na pierwszy i ostatni element (tzw. głowę i ogon) oraz swój aktualny rozmiar.

Wymagania dotyczące implementacji:

Należy zaimplementować listę dwukierunkową w C++ z wykorzystaniem mechanizmu szablonów (templates), co pozwoli na przechowywanie danych dowolnego typu.
Interfejs listy powinien udostępniać następujące funkcje:
Dodawanie elementu na końcu listy,
Dodawanie elementu na początku listy,
Usuwanie pierwszego i ostatniego elementu,
Wyszukiwanie elementu i jego usuwanie,
Pobieranie i ustawianie danych dla elementu o określonym indeksie,
Dodawanie elementu z zachowaniem porządku (jeśli dotyczy),
Czyszczenie całej listy,
Konwersję listy do postaci tekstowej.
Należy zadbać o odpowiednie zarządzanie dynamicznie przydzielaną pamięcią.
Cel dodatkowy:

Przeprowadzenie pomiarów czasowych dla operacji dodawania, wyszukiwania oraz usuwania elementów przy różnych rozmiarach listy.
Instrukcje dodatkowe:

Można rozważyć użycie wskaźników do przechowywania danych w węzłach.
Plik nagłówkowy (.h) może zawierać definicję klasy, a plik źródłowy (.cpp) główną funkcję i testy.
Kod źródłowy powinien być zgodny z wytycznymi dotyczącymi formatowania i przesyłania plików na pocztę uczelni.
Szczegóły realizacji eksperymentu: W funkcji main() należy:

Dodawać elementy do listy, przeprowadzać pomiary czasowe i raportować wyniki.
Wyszukiwać losowe elementy, usuwać je, a następnie mierzyć czas operacji.
Wyczyścić listę po każdym teście.
Wskazówki techniczne:

Do losowania danych można użyć funkcji rand().
Do pomiaru czasu można użyć funkcji clock() z biblioteki <time.h>.