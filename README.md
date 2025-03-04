# Projekt bazy danych i hurtowni danych

## Opis problemu i założenia projektowe

Tematem projektu jest baza danych i hurtownia danych dla sieci salonów komórkowych. Poczatkowo opracowano schemat bazy danych, który następnie został przekształcony w hurtownię danych.

### Kluczowe założenia:

- Klient może posiadać wiele umów, a w każdej umowie może być wiele telefonów. Klient jest opisany poprzez: imię, nazwisko, numer telefonu oraz numer dowodu osobistego.

- Pracownik może pracować tylko w jednym salonie i może posiadać tylko jedno stanowisko, które definiuje jego pensję.

- Telefony są opisane przez: markę, model oraz kolor.

- Salon posiada magazyn przechowujący określone telefony i ich ilość.

- Adresy klientów i salonów zawierają ulicę, miasto i województwo.

## Struktura bazy danych

Kluczowe tabele:

- Marka (Id_marka, Nazwa)

- Model (Id_model, Nazwa, Marka_Id_marka)

- Kolor (Id_kolor, Nazwa)

- Telefony (Id_telefon, Kolor_Id_kolor, Model_Id_model)

- Magazyn (Id_magazyn, Ilosc, Telefony_Id_telefon, Salon_Id_salon)

- Salon (Id_salon, Nazwa, Ulica_Id_ulica)

- Ulica (Id_ulica, Nazwa, Miasta_Id_miasta)

- Miasta (Id_miasta, Nazwa, Wojewodztwo_Id_wojewodztwa)

- Wojewodztwo (Id_wojewodztwa, Nazwa)

- Klient (Id_klient, Imie, Nazwisko, Nr_telefonu, Nr_dowodu_osobistego, Ulica_Id_ulica)

- Pracownicy (Id_pracownik, Imie, Nazwisko, Salon_Id_Salon, Stanowisko_Id_stanowisko)

- Stanowisko (Id_stanowiska, Nazwa, Pensja)

# Transformacja bazy danych do hurtowni

Hurtownia danych przechowuje informacje o zawieranych umowach w salonach komórkowych.

#### Główna tabela faktów:

- W_UMOWA (Id_umowa, Cena + klucze obce do tabel wymiarowych)

#### Tabele wymiarów:

- W_Wojewodztwo

- W_Miasta

- W_Ulica

- W_Klient (bez numeru telefonu i numeru dowodu osobistego)

- W_Salon

- W_Pracownicy (Imie, Nazwisko)

- W_Stanowisko

- W_Marka

- W_Model

- W_Kolor

- W_Telefony

- W_Magazyn

## Proces ładowania danych

Dane są przenoszone z bazy do hurtowni poprzez procedury:

CREATE OR REPLACE PROCEDURE Load_Magazyn AS  
BEGIN
    INSERT INTO W_Magazyn SELECT Id_magazyn FROM Magazyn;
END;  
/

Podobne procedury istnieją dla pozostałych tabel.

Wszystkie procedury są uruchamiane za pomocą:

EXECUTE Load_Magazyn;
EXECUTE Load_Kolor;
...
EXECUTE Load_UMOWA;



## Proces importu danych

Dane do bazy zostały załadowane z plików .csv wygenerowanych w C++.

### Kluczowe kroki:

- Pliki .csv - zawierają dane.

- Pliki kontrolne .ctl - definiują polecenia SQLLoadera.

- Plik wsadowy .bat - automatyzuje proces importu.

## Podsumowanie

Projekt pozwolił na zdobycie praktycznej wiedzy o:

- Projektowaniu baz danych i ich transformacji na hurtownie danych.

- Optymalizacji zapytań SQL.

- Automatyzacji ładowania danych przy użyciu SQLLoadera.
