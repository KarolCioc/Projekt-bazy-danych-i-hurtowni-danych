--Liczba klientów dla kombinacji marek telefonów, modeli, kolorów.
SELECT
    NVL((SELECT nazwa FROM w_marka WHERE id_marka = w_umowa.w_marka_id_marka),'Wszystkie marki') AS MARKA,
    NVL((SELECT nazwa FROM w_model WHERE id_model = w_umowa.w_model_id_model),'Wszystkie modele') AS MODEL,
    NVL((SELECT nazwa FROM w_kolor WHERE id_kolor = w_umowa.w_kolor_id_kolor),'Wszystkie kolory') AS KOLOR,
    COUNT (w_umowa.w_klient_id_klient) AS LICZBA_KLIENTOW
FROM w_umowa
GROUP BY CUBE(w_umowa.w_marka_id_marka,w_umowa.w_model_id_model,w_umowa.w_kolor_id_kolor);

--Œrednia cena umów dla kombinacji marek telefonów i stanowisk pracownikow.
SELECT 
    NVL((SELECT nazwa FROM w_marka WHERE id_marka = w_umowa.W_marka_Id_marka),'Wszystkie marki') AS MARKA,
    NVL((SELECT nazwa FROM w_stanowisko WHERE id_stanowiska = w_umowa.W_stanowisko_Id_stanowiska),'Wszystkie stanowiska') AS STANOWISKO,
    ROUND(AVG(w_umowa.cena),2) AS SREDNIA_CENA_UMOW
FROM w_umowa
GROUP BY CUBE (w_umowa.w_marka_id_marka, w_umowa.w_stanowisko_id_stanowiska)
ORDER BY MARKA;

--Œrednia wartoœæ umów w danym wojewodztwie.
SELECT
    NVL((SELECT nazwa FROM w_wojewodztwo WHERE id_wojewodztwa = w_umowa.W_wojewodztwo_Id_wojewodztwa),'Wszystkie wojewodztwa') AS NAZWA_WOJEWODZTWA,
    NVL((SELECT nazwa FROM w_miasta WHERE id_miasta = w_umowa.W_miasta_Id_miasta),'Wszystkie miasta') AS MIASTO,
    NVL((SELECT nazwa FROM w_ulica WHERE id_ulica = w_umowa.W_ulica_Id_ulica),'Wszystkie kolory') AS ULICA,
    ROUND(AVG(w_umowa.cena),2) AS srednia_cena_umowy
FROM w_umowa
GROUP BY CUBE(w_umowa.w_wojewodztwo_id_wojewodztwa, w_umowa.w_miasta_id_miasta, w_umowa.w_ulica_id_ulica)
ORDER BY NAZWA_WOJEWODZTWA;