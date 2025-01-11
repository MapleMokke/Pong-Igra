## Pong-Igra 🏓
Modernizirana verzija klasične Pong igre, jedne od prvih arkadnih igara napravljena 1972. godine. Izrađena u C++ jeziku koristeći konzolnu grafiku. 
Igra nudi sudjelovanje dvoje igrača s kontrolom palica, sustavom bodovanja i prilagođene zaslone za početak i kraj.

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

- **Dodatne tipke:**		
	- **Enter:** Započni igru ili ponovno pokreni nakon završetka.
	- **Q:** Izađi iz igre.

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
  - Dinamično kretanje lopte koja mijenja smjer prilikom sudara ili zidom.  
  - Rezultat se prikazuje na dnu zaslona.  
- **Završni zaslon**:  
  Prikazuje pobjednika, konačni rezultat svakog igrača i povijest svih prijašnjih pobjednika.  
- **Zaslon zahvale**:  
  Prikazuje poruku zahvale prije zatvaranja igre.

---

## 💻 Zahtjevi sustava
- **Operativni sustav**: Windows (zbog korištenja `conio.h` i Windows API funkcija).
- **Kompajler**: C++ kompajler s podrškom za C++11 ili novije verzije (npr. GCC, MSVC).

---

## ⚙️ Postavljanje i instalacija
1. Spremite izvorni kod igre u datoteku (svaki .cpp i .hpp file, kao što su game.hpp, game.cpp, main.cpp i ostali).
2. Otvorite svoj IDE (npr. Visual Studio, CodeBlocks, ...).
3. Kreirajte novi projekt i dodajte sve preuzete .cpp i .hpp datoteke.
4. Kompajlirajte program preko opcije Build ili Kompajliraj.
5. Pokrenite igru preko opcije Run ili Pokreni.

---

## ⚠️ Problemi tijekom izrade  
- **Bljeskanje ekrana**: Tijekom igre, zbog učestalog ažuriranja prikaza u konzoli, pojavilo se bljeskanje ekrana. Problem je riješen kombinacijom funkcije za sakrivanje pokazivača (`hideCursor`) i optimizacijom crtanja elemenata.  
	- **Sakrivanje pokazivača**: implementacija prilagođene funkcije `hideCursor`, koja je ujedno pomogla i u rješavanju problema s bljeskanjem ekrana.  
	- **Pozicioniranje elemenata**: Ručno pozicioniranje elemenata na konzolnom zaslonu oslanjalo se na funkciju `gotoxy`
- **Optimizacija dinamičke fizike lopte**: Precizno podešavanje slučajnih smjerova lopte bilo je izazovno kako bi se osigurala ravnoteža između izazova i igrivosti.  
- **Ograničenja prenosivosti**: Korištenje specifičnih Windows funkcija (poput `conio.h`) onemogućilo je jednostavno pokretanje igre na drugim operativnim sustavima.  

---

## 💡 Moguća poboljšanja  
- Zamjena `conio.h` biblioteke s prenosivim rješenjem za širu kompatibilnost (npr. korištenje cross-platform knjižnica poput SDL-a).  
- Dodavanje naprednih opcija igre, poput različitih razina težine ili modova za jednog igrača protiv računala.  
- Unapređenje vizualnog prikaza igre uvođenjem grafičkog sučelja (GUI) koristeći moderni grafički framework.  
- Proširenje povijesti pobjednika s opcijom spremanja podataka u datoteku radi dugoročnog praćenja rezultata.  
- Optimizacija kontrole palica za još preciznije upravljanje tijekom igre.

---
  
## 🛠️ Dodatne Informacije
- **Programski jezik:** C++
- **Osnovne klase igre:**
	- **Screen:** Bazna klasa za upravljanje zaslonima poput početnog, završnog i zaslona zahvale.
	- **Paddle:** Predstavlja palice igrača, upravljajući njihovim položajem i kretanjem.
	- **Ball:** Upravljanje ponašanjem lopte, uključujući položaj, smjer i sudare.
	- **Game:** Upravljanje petljom igre, bodovanjem, unosima i općom logikom.
- **Praćenje rezultata:** Pobjednik svake igre bilježi se u povijesti prikazanoj nakon meča.

---

## 📞 Kontakt i povratne informacije
Ako primijetite poteškoće ili imate prijedloge za poboljšanje, slobodno nam se obratite ili podijelite svoje ideje. Vaše povratne informacije su nam iznimno vrijedne i pomažu u daljnjem razvoju igre! 😊

## Uživajte u igri i neka najbolji igrač pobijedi! 🏆
