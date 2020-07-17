# Dangerous Road
Gracz musi przejść przez autostradę składającą się z 16 pasów uikajac kolizji z pojazdami. Przemieszczanie bohatera odbywa się za pomocą klawiszy W,S,A,D. Aby ukończyc poziom gracz musi się przemieścić z pozycji startowej:

![](textury/dolnypas.png) 

do końca poziomu:

![](textury/END.png) 

Przeszkodę stanowią samochody których kolizja z graczem powoduje utrate żyć oraz powrót na pozycje startową lub pas bezpieczeństwa.
Kolizja z policeCar oraz dhlCar powoduje utratę 5 żyć oraz powrót gracza na pozycje startową , a kolizja z recCar oraz greenCar powoduje utratę jednego życia i powrót na 
pozycje startową(redCar) lub pas bezpieczeństwa(greenCar).Po ukończeniu poziomu gracz wraca na pozycje startową, a pojazdy przyspieszają o ustaloną wartość.
Po rozpoczęciu gry przez 10s gracz porusza sie "normalnie" tj.naciśniecie W-ruch do góry, naciśnięcie S-ruch w dół itd. Po upływie 10s sterowanie odwraca się na czas 5s.


Gra polegająca na pokonaniu przez gracza "autostrady" w poprzek(od bottom do top) .Gracz będzie musiał unikać samochodów jadących z obydwu stron[ 5-8(ilość ta może ulec zmianie w procesie pisania) pasów z samochodami początkowo jadącymi w lewo,5-8 pasów z samochodami początkowo jadącymi w prawo].
Plansza będzie się składała z siatki pól, gracz sterowany klawiszami w,a,s,d lub "strzałkami" będzie się przemieszczał z pola na pole o stałą odległość(możiwość ruchu góra,dół,prawo,lewo). Samochodu będą poruszać się ze stałą prędkością z pola na pole od jednej krawędzi ekranu do drugiej
(przy udeżeniu w krawędź zmieniac sie będzie prędkosć X i Y na wartości przeciwne aby pojazd wrócił na ten sam tor ruchu).Pomiędzy 5 pasami będzie pas bezpieczeństwa ciągnący się na całą szerokośc ekranu gdzie gracz będzie mógł odpocząć.
Po kolizji gracza z "normalnym pojazdem"(np zwykły samochod osobowy) gracz wróci na start(lub na pas bezpieczeństwa jeśli przejdzie przez pierwszą połowe drogi).
Chciałbym również stworzyć specjalne pojazdy(w przeciwieństwie do zwykłych pojazdów te bedą przejeżdżały przez ekran i po wyjechaniu za krawędź znikną), pojazdy te będą sie pojawiały losowo,
lub po określonej liczbie ruchów gracza.
Kolizja tych pojazdów z graczem spowoduje odwrócenie sterowania(np po napotkaniu karetki) które wróci do normy po wykonaniu określonej liczby ruchów. Plansza będzie reprezentowana za pomocą wektora z argumentami opisującymi ilość pojazdów oraz ich prędkość.
Gra będzie oferowała nieskończoną ilość poziomów które bedą się różnić prędkością przeciwników oraz ich ilością na jednym pasie(początkowo na każdym pasię będzie jeden przecwnik)
(możliwość rywalizacji między graczami analogicznie do gry flappy bird-kto dalej zajdzie ten lepszy).

Na poniższym przykładzie gracz jest oznaczony jako "strzałka"

!!!!!!!!!!!!POPRAWIONE!!!!!!!:

Każdy pas będzie zapisany jako kolejny krok,prędkość samochodów będzie 2-3 razy większa od prędkości bohatera(wartość ta będzie wzrastać wraz z kolejnymi poziomami,oczywiście tak aby rozgrywka była możliwa)

Pojazdy które miały się pojawiać losowo będą obecne od początku rozgrywki lecz ich prędkość będzie znacznie większa od pozostałych(4-5 razy).
Zmiana sterowania nastąpi co 10 sekund i beędzie trwać przez 5 sekund

Gracz zakończy poziom po osiąnięciu danego punktu po drugiej stronie planszy.

# KLASY:
# Player
 * Animate()- odpowiada za "normalne" pouszanie gracza tj. w-ruch do góry,s-ruch w dół,a-ruch w lewo,d-ruch w prawo
 * checkCollision()- sprawdza kolizje z poszczegolnymi obiektami
 * Start()- Nadaje bochaterowi wartości umożliwiajace poruszanie
 * LvL_Counter() - Wyświetla numer poziomu na którym znajduje sie gracz
 * Move()- W zależności od czasu decyduje o sposobie poruszania gracza
 * LvlUpdate()-Aktualizuje poziom,oraz przywraca gracza na pozycje startu
 * Zycia()-Aktualizuje liczbę żyć gracza oraz kończy ge jeśli gracz utraci wszystkie zycia 
 * ReverseAnimate()-odpowiada za "odwrócone" poruszanie tj. naciśnięcie któregokolwiek z klawiszy w,s,a,d daje przeciwny efekt niż w funkcji Animate()
 
 # Vehicle
 * Lvl()-zwiększa prędkość pojazdów wraz z wzrostem poziomu
 * Start()-najadę początkową predkość
 
 # Road
 * Render()-Odpowiada za narysowanie drogi
 
 # SceneElements
 * Render()
 * Draw()-Funkcja przekazująca obikety do narysowania
 
 # Sprite
 * SetBounds()-Funkcja pobierajaca informacje o wymiarach ekranu
 * TimeReset()-Funkcja restartująca czas
 * GiveBounds()-Funkcja zwracająca granice obiektów
 * MoveSound()-Funkcja odpowiadająca za dzwięk poruszania gracza
 * HitSound()-Funkcja odpowiadająca za dzwiek kolizji gracza z samochodem
 * NextLvlSound()-Funkcja odpowiadająca za dzwięk ukończenia poziomu
 * ObjectColission()-Fnunkcja odpowiadająca za kolizje z samochodami
 * Animate()-Funkcja odpowiadająca za poruszanie
 * Start()-Fukcja odpowiadająca za nadanie pocztkowej prędkości
 
 



