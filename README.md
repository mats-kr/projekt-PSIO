# Dangerous Road
Gracz startujący z 10 życiami musi przejść przez autostradę składającą się z 16 pasów uikajac kolizji z pojazdami. Przemieszczanie bohatera odbywa się za pomocą klawiszy W,S,A,D. Aby ukończyc poziom gracz musi się przemieścić z pozycji startowej do końca poziomu, z możliwością odpoczynku na "Pasie bezpieczeństwa". Przeszkodę stanowią samochody
(jadące z prawej do lewej-DhlCar oraz RedCar, jadące z lewej do prawej-policeCar oraz GreenCar) których kolizja z graczem powoduje utrate żyć oraz powrót na pozycje startową lub pas bezpieczeństwa.
Kolizja z PoliceCar oraz DhlCar powoduje utratę 5 żyć oraz powrót gracza na pozycje startową , a kolizja z RedCar oraz GreenCar powoduje utratę jednego życia i powrót na 
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
# Player-Klasa odpowiadająca za gracza
 * Animate()- Metoda odpowiadająca za "normalne" pouszanie gracza tj. w-ruch do góry,s-ruch w dół,a-ruch w lewo,d-ruch w prawo
 * checkCollision()- Metoda odpowiadająca zasprawdzenie kolizji z poszczegolnymi obiektami
 * Start()- Metoda odpowiadająca za nadanie bochaterowi wartości umożliwiajace poruszanie
 * LvL_Counter() -Metoda odpowiadająca za wyświetlenie numeru poziomu na którym znajduje sie gracz
 * Move()- W zależności od czasu decyduje o sposobie poruszania gracza
 * LvlUpdate()-Metoda odpowiadająca za aktualizacje poziou,oraz przywracanie gracza na pozycje startu
 * Zycia()-Metoda odpowiadająca za aktualizacje liczby żyć gracza oraz skończenie gry jeśli gracz utraci wszystkie zycia 
 * ReverseAnimate()-Metoda odpowiadająca za "odwrócone" poruszanie tj. naciśnięcie któregokolwiek z klawiszy w,s,a,d daje przeciwny efekt niż w funkcji Animate()
 
 # Vehicle-Klasa główna odpowiadająca za pojazdy
 * Lvl()-Metoda odpowiadająca za zwiększenie prędkości pojazdów wraz z wzrostem poziomu
 * Start()-Metoda odpowiadająca za nadanie początkowej predkości
 
  # GreenCar-Podklasa klasy Vehicle
 * Animate()-Metoda odpowiadająca za pouszanie się samochodów
 
 # DhlCar-Podklasa klasy Vehicle
 * Analogicznie do Greencar
 
 # PoliceCar-Podklasa klasy Vehicle
 * Analogicznie do GreenCar
 
 # RedCar-Podklasa klasy Vehicle
 * Analogicznie do GreenCar
 
 
 
 # Sprite-Klasa główna po której dziedziczą klasy Player oraz Vehicle
 * SetBounds()-Metoda odpowiadająca za pobranie informacji o wymiarach ekranu
 * TimeReset()-Metoda odpowiadająca za reset czasu
 * GiveBounds()-Metoda odpowiadająca za zwrócenie granic obiektów
 * MoveSound()-Metoda odpowiadająca za dzwięk poruszania gracza
 * HitSound()-Metoda odpowiadająca za dzwiek kolizji gracza z samochodem
 * NextLvlSound()-Metoda odpowiadająca za dzwięk ukończenia poziomu
 * ObjectColission()-Metoda odpowiadająca za kolizje z samochodami
 * Animate()-Metoda odpowiadająca za poruszanie
 * Start()-Metoda odpowiadająca za nadanie pocztkowej prędkości
 

 
 # SceneElements-Klasa główna odpowiadająca za elementy sceny takie jak granice, pas bezpieczeństwa oraz droga
 * Render()-Funkcja odpowiadająca za rysowanie obiektów
 * RenderInfo()-Funkcja odpowiadająca za wyświetlenie informacji
 * RestartTime()-Funkcja odpowiadająca za resetowanie czasu
 * LoadTexture()-Funkcja odpowiadająca za wczytanie tekstury
 
 # SceneLabels-Podklasa klasy SceneElements
 * DisplayInstructions()-Funkcja odpowiadająca za instrukcje na początku gry
 * MoveInfo()-Funkcja odpowiadająca za informacje o sposobie poruszania
 * DrawObject()-Funkcja odpowiadająca za przekazanie obiketu do narysowania
 * Render()-Funkcja odpowiadająca za wyświetlenie pierwszych dwóch funkcji
 * LoadFont()-Funkcja odpowiadająca za wczytanie znaków tekstowych
 
  # SceneBorder-Podklasa klasy SceneElements odpowiadająca za miejsce startu gry,pas bezpieczeństwa oraz miejsce końca gry
 * RenderInfo()-Analogicznie do SceneElements
 * Render()-nalogicznie do SceneElements
 
 # Road-Podklasa klasy SceneElements odpowiadająca za Drogę
 * Render()-Funkcja odpowiadająca za rysowanie obiektu
 
 
 
 
 
 


