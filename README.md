# PROIekt


## Suggestions for a good README
Every project is different, so consider which of these sections apply to yours. The sections used in the template are suggestions for most open source projects. Also keep in mind that while a README can be too long and detailed, too long is better than too short. If you think your README is too long, consider utilizing another form of documentation rather than cutting out information.

## Name
Saper

## Description
Saper to logiczna gra komputerowa, która wymaga umiejętności dedukcyjnych oraz spostrzegawczości. Gracz musi odkryć pola na planszy, unikając min, które są ukryte wśród nich. Każde odkrycie pola dostarcza informacji na temat liczby min znajdujących się w jego sąsiedztwie, dzięki czemu gracz może wykonać dedukcje i odkryć bezpieczne pola. Gra saper wymaga strategii oraz podejmowania ryzykownych decyzji, a jej dynamiczny charakter i losowe rozmieszczenie min sprawiają, że każda gra jest unikalnym wyzwaniem.

## Authors and acknowledgment
Tomasz Zalewski, Igor Płoszaj, Antoni Kowalski grupa 102 poniedziałek 16:15

## Division of Work
Tomasz Zalewski - responsble for Class Cell
Igor Płoszaj - responsble for Class Game
Antoni Kowalski - responsble for Class Grid

## Usage
Pierwsze menu wygląda następująco:
![Imie gracza](images/Zrzut_ekranu_2023-06-05_142655.png)

## Badges
On some READMEs, you may see small images that convey metadata, such as whether or not all the tests are passing for the project. You can use Shields to add some to your README. Many services also have instructions for adding a badge.

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Installation
Within a particular ecosystem, there may be a common way of installing things, such as using Yarn, NuGet, or Homebrew. However, consider the possibility that whoever is reading your README is a novice and would like more guidance. Listing specific steps helps remove ambiguity and gets people to using your project as quickly as possible. If it only runs in a specific context like a particular programming language version or operating system or has dependencies that have to be installed manually, also add a Requirements subsection.

## Milestones
week
1 Struktury Klas
2 Działające Klasy
3 Działająca gra
4 Dodanie rankingu oraz poprawianie błędów

## Meetings
We wtorki

## Classes
1. Klasa Game - odpowiada za ogólną logikę gry i połączenie z interfejsem użytkownika.
2. Klasa Board - reprezentuje planszę gry i przechowuje informacje o minach oraz otwartych polach.
3. Klasa Cell - reprezentuje pojedyncze pole na planszy i przechowuje informacje o swoim stanie oraz liczbie min sąsiadujących pól.
    Flag
    Mine
    Number
    Covered

Klasa Game dziedziczy po klasie Board.
Klasy Flag, Mine, Number będą dziedziczyć po klasie Cell
Klasa Board składa się z obiektów klasy Cell.

Hierarchia:

          Game
           |
          Board
           |
          Cell
       /   |   \
    Flag  Mine  Number
     