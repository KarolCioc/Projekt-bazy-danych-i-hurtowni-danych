-- Zestawienie iloœci umów w danym mieœcie i salonach.
SELECT
  NVL((SELECT nazwa FROM w_miasta WHERE id_miasta = w_umowa.W_miasta_Id_miasta),'Wszystkie miasta') AS nazwa_miasta,
  NVL((SELECT nazwa FROM w_salon WHERE id_salon = w_umowa.W_Salon_Id_salon),'Wszystkie salony') AS nazwa_salonu,
  COUNT(w_umowa.id_umowa) AS ILOSC
FROM w_umowa
GROUP BY ROLLUP(w_umowa.W_miasta_Id_miasta, w_umowa.W_Salon_Id_salon)
ORDER BY ILOSC, nazwa_miasta asc;

--Zestawienie ilosci umow w danych salonach dla pracowników.
SELECT 
    NVL((SELECT nazwa FROM w_salon WHERE id_salon = w_umowa.w_salon_id_salon),'Wszystkie salony') AS NAZWA_SALONU,
    NVL((SELECT imie FROM w_pracownicy WHERE id_pracownik = w_umowa.w_pracownicy_id_pracownik),'Wszyscy imie') AS IMIE,
    NVL((SELECT nazwisko FROM w_pracownicy WHERE id_pracownik = w_umowa.w_pracownicy_id_pracownik),'Wszystkie nazwiska') AS NAZWISKO,
    COUNT (w_umowa.id_umowa) AS ILOSC
FROM w_umowa
GROUP BY ROLLUP(w_umowa.w_salon_id_salon, w_umowa.w_pracownicy_id_pracownik)
ORDER BY ILOSC ASC;


--Ilosc zawartych umow dla danych modeli telefonow.
SELECT 
    NVL((SELECT nazwa FROM w_marka WHERE id_marka = w_umowa.W_marka_Id_marka),'Wszystkie marki') AS marka,
    NVL((SELECT nazwa FROM w_model WHERE id_model = w_umowa.W_model_Id_model),'Wszystkie modele') AS model,
    COUNT(w_umowa.id_umowa) AS ILOSC
FROM 
    w_umowa
GROUP BY ROLLUP(w_umowa.w_marka_id_marka,w_umowa.w_model_id_model,w_umowa.w_kolor_id_kolor);

