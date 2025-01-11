# Pong-Igra 🏓
Modernizirana verzija klasične Pong igre, izrađena u C++ jeziku koristeći konzolnu grafiku.  
Igra nudi jednozaslonsku igru za dva igrača s kontrolom palica, sustav bodovanja i prilagođene zaslone za početak, kraj i zahvalu.

---

## 📋 Značajke igre
- **Igra za dva igrača**: Sudjelujte u natjecateljskom meču gdje svaki igrač kontrolira svoju palicu.
- **Dinamična mehanika lopte**: Lopta nasumično mijenja smjer prilikom udarca u palicu, čime se igra čini nepredvidivom i uzbudljivom.
- **Interaktivni zasloni**:
  - **Početni zaslon**: Opcije za početak igre ili izlazak.
  - **Završni zaslon**: Prikazuje konačne rezultate i povijest pobjednika.
  - **Zaslon zahvale**: Iskazuje zahvalnost na kraju igre.
- **Sustav bodovanja**: Prvi igrač koji osvoji 5 bodova pobjeđuje.
- **Povijest pobjednika**: Prati i prikazuje pobjednike svih završenih mečeva.
- **Jednostavne kontrole**: Intuitivni unosi preko tipkovnice za brz odgovor tijekom igre.

---

## 🎮 Kontrole
| **Igrač** | **Tipka** | **Akcija**                    |
|-----------|-----------|-------------------------------|
| Igrač 1   | W         | Pomicanje palice prema gore.  |
|           | S         | Pomicanje palice prema dolje. |
| Igrač 2   | I         | Pomicanje palice prema gore.  |
|           | K         | Pomicanje palice prema dolje. |

Dodatne tipke:		
	Enter: Započni igru ili ponovno pokreni nakon završetka.
	Q: Izađi iz igre.

---

## 🕹️ Kako se igra?
1. Pokrenite igru iz terminala.
2. Na početnom zaslonu pritisnite **Enter** za početak ili **Q** za izlazak.
3. Koristite svoju palicu kako biste odbili loptu prema protivniku.
4. Osvojite bodove kada protivnik ne uspije vratiti loptu.
5. Prvi igrač koji osvoji **5 bodova** pobjeđuje.
6. Nakon završetka igre:
   - Pritisnite **Enter** za novu igru.
   - Pritisnite **Q** za izlazak i prikaz zaslona zahvale.

---

## 🎨 Vizualni prikaz
- **Početni zaslon**:  
  Zaslon dobrodošlice s uputama za početak ili izlazak.  
- **Igra**:  
  - Lijeva i desna palica koje kontroliraju igrači.  
  - Dinamično kretanje lopte koja mijenja smjer prilikom sudara.  
  - Rezultat se prikazuje na dnu zaslona.  
- **Završni zaslon**:  
  Prikazuje pobjednika, konačni rezultat i povijest svih prijašnjih pobjednika.  
- **Zaslon zahvale**:  
  Prikazuje poruku zahvale prije zatvaranja igre.

---

## 💻 Zahtjevi sustava
- **Operativni sustav**: Windows (zbog korištenja `conio.h` i Windows API funkcija).
- **Kompajler**: C++ kompajler s podrškom za C++11 ili novije verzije (npr. GCC, MSVC).

---

## ⚙️ Postavljanje i instalacija
1. Spremite izvorni kod igre u datoteku, primjerice `pong.cpp`.
2. Otvorite terminal ili naredbeni redak.
3. Kompajlirajte program:
   ```bash
   g++ -o pong pong.cpp
4. Pokrenite igru:
  
## 🛠️ Dodatne Informacije
Programski jezik: C++
Osnovne klase igre:
Screen: Bazna klasa za upravljanje zaslonima poput početnog, završnog i zaslona zahvale.
Paddle: Predstavlja palice igrača, upravljajući njihovim položajem i kretanjem.
Ball: Upravljanje ponašanjem lopte, uključujući položaj, smjer i sudare.
Game: Upravljanje petljom igre, bodovanjem, unosima i općom logikom.
Dinamična fizika lopte: Lopta nasumično mijenja smjer prilikom sudara, što dodaje sloj izazova.
Praćenje rezultata: Pobjednik svake igre bilježi se u povijesti prikazanoj nakon meča.

## 📞 Kontakt i povratne informacije
Ako naiđete na probleme ili imate prijedloge, slobodno doprinesite ili ih prijavite. Vaše povratne informacije su vrlo cijenjene! 😊

Uživajte u igri i neka najbolji igrač pobijedi! 🏆
