# Minesweeper-project
Intoduction to programming Practicum Course - final project.

При започването на играта потребителят трябва да може да избере на каква размерност да играе (3 <= N <= 10). След това трябва да избере колко мини да бъдат "скрити", броят трябва да е в интервала [1 : 3N]. 
Ако някои от стойностите не са въведат правилно от потребителя, то трябва да се изведе подходящо съобщение и да бъде "приканен" да въведе отново.
В конзолата трябва да се изпълняват команди от вида:

 [command] [x coordinate] [y coordinate] // [действие] [ред] [колона]
Където [command] е open, mark или unmark, а след него стоят координатите на квадратчето.

>open - отваря квадратчето. Ако там седи мина - край на играта!

>mark - маркира квадратчето като "мина". Ако всички мини са маркирани и всички други квадратчета са отворени, играта приключва с успех!

>unmark - отмаркира квадрачето като "мина". Ако квадратчето не е било маркирано, то се извежда подходящо съобщение за грешка.
