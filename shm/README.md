# Symulator Handlu Morskiego - SHM
aaaaaappppp
Wykorzystaj kod napisany podczas zajęć. Jeśli go nie masz to skorzystaj z kodu w katalogu [solutions](../module1/solutions)

___

## Zadanie 1

W klasie `Cargo` napisz operator porównania (`operator==`), który będzie sprawdzał, czy towary są takie same.

___

## Zadanie 2

Do klasy `Cargo` dopisz gettery oraz odpowiedni konstruktor, który wypełni wszystkie pola tej klasy.

___

## Zadanie 3

Napisz klasę `Island`, która będzie posiadała zmienną `Coordinates position_` oraz odpowiedni getter.

Klasa `Coordinates` ma określać współrzędne na mapie. Również ją napisz. Powinna przyjmować w konstruktorze 2 parametry `positionX`, `positionY` oraz operator porównania.
<!-- Klasa `Island` powinna posiadać także sklep. -->

___

## Zadanie 4

Napisz klasę `Map`, która będzie posiadała `std::vector<Island&>` przechowujący wszystkie wyspy na mapie, oraz zmienną `Island* currentPosition_` określającą aktualną pozycję gracza na mapie.

___

## Zadanie 5

W klasie `Map` utwórz konstruktor bezargumentowy, a w jego ciele utwórz 10 wysp, które przechowasz w `std::vector<Island&>`.
Do wygenerowania losowych wartości pozycji wysp na mapie skorzystaj z [przykładu na cppreference](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution).
Wymyśl sposób, aby pozycje wysp się nie powielały.

___

## Zadanie 6

W klasie `Map` napisz funkcję

`Island* getIsland(const Island::Coordinates& coordinate)`

Powinna ona przeszukać `std::vector<Island&>` i zwrócić szukaną wyspę.

___

## Zadanie 7

Napisz klasę `Player`, która posiadać będzie 3 pola:

* `std::unique_ptr<Ship> ship_`
* `money_`
* `availableSpace_`

Dopisz także odpowiednie gettery oraz konstruktor.

Dopisz także 2 funkcje, które powinny zwracać dane ze statku:

* `size_t getSpeed() const`
* `Cargo* getCargo(size_t index) const`

___

## Zadanie 8

W klasie `Player` napisz prywatną funkcję, która obliczać będzie `availableSpace_` na podstawie aktualnej ilości towaru na statku.
