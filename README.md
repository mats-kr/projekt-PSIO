# Dangerous Road
Gracz startujący z 10 życiami musi przejść przez autostradę składającą się z 16 pasów uikajac kolizji z pojazdami. Przemieszczanie bohatera odbywa się za pomocą klawiszy W,S,A,D. Aby ukończyc poziom gracz musi się przemieścić z pozycji startowej do końca poziomu, z możliwością odpoczynku na "Pasie bezpieczeństwa". Przeszkodę stanowią samochody
(jadące z prawej do lewej-DhlCar oraz RedCar, jadące z lewej do prawej-policeCar oraz GreenCar) których kolizja z graczem powoduje utrate żyć oraz powrót na pozycje startową lub pas bezpieczeństwa.
Kolizja z PoliceCar oraz DhlCar powoduje utratę 5 żyć oraz powrót gracza na pozycje startową , a kolizja z RedCar oraz GreenCar powoduje utratę jednego życia i powrót na 
pozycje startową(redCar) lub pas bezpieczeństwa(greenCar).Po rozpoczęciu gry przez 10s gracz porusza sie "normalnie" tj.naciśniecie W-ruch do góry, naciśnięcie S-ruch w dół itd. Po upływie 10s sterowanie odwraca się na czas 5s.Po ukończeniu poziomu gracz wraca na pozycje startową, a pojazdy przyspieszają o ustaloną wartość.Gra oferuje nieskończoną ilość
poziomów-kto zajdzie dalej ,ten lepszy.



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
 
 
 # Reprezentacja graficzna obiektów
 * RedCar 
 ![](texstury/redcar.png)
 
 
 


