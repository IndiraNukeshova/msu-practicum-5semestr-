### A Алгоритм Флойда
Полный ориентированный взвешенный граф задан матрицей смежности. Постройте матрицу кратчайших путей между его вершинами. Гарантируется, что в графе нет циклов отрицательного веса.

В первой строке вводится единственное число N (1 ≤ N ≤ 100) – количество вершин графа. В следующих N строках по N чисел задается матрица смежности графа (j-ое число в i-ой строке соответствует весу ребра из вершины i в вершину j). Все числа по модулю не превышают 100. На главной диагонали матрицы – всегда нули.

Выведите N строк по N чисел – матрицу кратчайших расстояний между парами вершин. j-ое число в i-ой строке должно быть равно весу кратчайшего пути из вершины i в вершину j.


### B Алгоритм Дейкстры
Правительство некоторой всем известной страны решило глобально перестроить дорожную систему – оно уже успело разрушить все дороги, и теперь нужно выстроить дорожную сеть заново. Новые двусторонние дороги можно строить между любыми двумя городами, и стоимость постройки дороги равна расстоянию между соответствующими городами. Однако в некоторых случаях ландшафт позволяет построить дорогу за другую цену, такие пары городов называются особыми. Правительство решило первым делом соединить два главных города данной страны – А и Б. Вам поручили разработать план постройки дорог, при котором суммарная стоимость всех построенных дорог будет минимально возможной, и при этом по построенным дорогам можно будет добраться из города А в город Б.

Первая строка содержит число N – количество городов в стране (1 ≤ N ≤ 104). Каждая из последующих N строк содержит по два целых числа, xi и yi – координаты соответствующего города (|xi|, |yi| ≤ 106). Далее содержится число M – количество особых пар городов (0 ≤ M ≤ min(104, N * (N − 1) / 2)). Далее в M строках содержится описание особых дорог, каждое состоит из трех целых чисел: u, v – пара различных городов, между которыми проходит особая дорога, и w – стоимости постройки соответствующей дороги (1 ≤ u, v ≤ N, 0 ≤ w ≤ 106). В последней строке содержатся номера городов А и Б (от 1 до N).

Выведите одно число – искомую минимальную длину. Ваш ответ должен отличаться от правильного не более чем на 10−5.

### C Система Непересекающихся Множеств
Одно разбросанное на островах Океании государство решило создать сеть автомобильных дорог (вернее, мостов). По каждому мосту можно перемещаться в обе стороны. Был разработан план очередности строительства мостов и известно, что после постройки всех мостов можно будет проехать по ним с каждого острова на каждый (возможно, через некоторые промежуточные острова).

Однако, этот момент может наступить до того, как будут построены все мосты. Ваша задача состоит в нахождении такого минимального количества мостов, после постройки которого (в порядке строительства по плану) можно будет попасть с любого острова на любой другой.

При решении задачи реализуйте класс TDisjointSetUnion с публичными методами FindSet (константный) и UnionSets. Должна быть реализована эвристика сжатия путей, а также случайный выбор родителя при объединении множеств или на основе ранговой эвристики.

Первая строка содержит два числа: N - число островов (1 ≤ N ≤ 100 000) и M – количество мостов в плане (1 ≤ M ≤ 200 000). В каждой следующей строке содержится описание моста – два числа x и y (0 ≤ x, y < N) – номера соединяемых островов.

Выведите в выходной файл одно число – минимальное количество построенных мостов, по которым можно попасть с любого острова на любой.

### D Минимальное Остовное Дерево
Печатной схемой называется плоская поверхность содержащей узлы и перемычки, соединяющие пары узлов. Мы будем рассматривать печатные схемы специального вида, где все узлы расположены в узлах прямоугольной сетки, а перемычки (вертикальные или горизонтальные) соединяют пары соседних узлов. Печатная схема называется связной, если любые два узла соединены друг с другом последовательностью перемычек. На вход дается печатная схема, где некоторые соседние узлы уже соединены перемычками. К ней необходимо добавить некоторое количество перемычек таким образом, чтобы схема стала связной. Стоимость вертикальной перемычки – 1, а горизонтальной – 2. Ваша программа должна по начальной печатной схеме определить количество добавляемых перемычек, минимальную стоимость такого добавления, а также вывести сами добавляемые перемычки.

Первая строка входного файла содержит два натуральных числа N и M – количество строк (1 ≤ N ≤ 100) и количество столбцов (1 ≤ M ≤ 100) соответственно. Каждый узел определяется своими координатами, нумерация начинается с верхнего левого угла (координаты (1, 1)). Далее дается описание решетки в виде N строк по M чисел. Каждое число обозначает связь узла (i, j) с узлами (i + 1, j) и (i, j + 1) в следующем формате: 0 – узел (i, j) не соединен ни с одним из узлов (i + 1, j) и (i, j + 1). 1 – узел (i, j) соединен только с узлом (i + 1, j) 2 – узел (i, j) соединен только с узлом (i, j + 1) 3 – узел (i, j) соединен и с узлом (i + 1, j), и с узлом (i, j + 1).

Первая строка должна содержать два числа K и V – количество добавленных перемычек и стоимость добавления соответственно. Каждая из следующих K строк должна содержать описание добавленной перемычки в формате i, j, d, где (i, j) – координаты начального узла, а d может принимать значения 1 или 2. d = 1 обозначает, что соединены узлы (i, j) и (i + 1, j), d = 2 – узлы (i, j) и (i, j + 1). Если решений несколько – выведите любое из них.

### E 0-1 BFS
В городе Н при невыясненных обстоятельствах территория одного из заводов превратилась в аномальную зону. Все подъезды к территории были перекрыты, а сама она получила название промзоны. В промзоне находятся N зданий, некоторые из них соединены дорогами. По любой дороге можно перемещаться в обоих направлениях.

Начинающий сталкер получил задание добраться до склада в промзоне. Он нашел в электронном архиве несколько карт территории промзоны. Так как карты составлялись разными людьми, то на каждой из них есть информация только о некоторых дорогах промзоны. Одна и та же дорога может присутствовать на нескольких картах.

В пути сталкер может загружать из архива на мобильный телефон по одной карте. При загрузке новой карты предыдущая в памяти телефона не сохраняется. Сталкер может перемещаться лишь по дорогам, отмеченным на карте, загруженной на данный момент. Каждая загрузка карты стоит 1 рубль. Для минимизации расходов сталкеру нужно выбрать такой маршрут, чтобы как можно меньшее число раз загружать карты. Сталкер может загружать одну и ту же карту несколько раз, при этом придется заплатить за каждую загрузку. Изначально в памяти мобильного телефона нет никакой карты.

Требуется написать программу, которая вычисляет минимальную сумму расходов, необходимую сталкеру, чтобы добраться от входа в промзону до склада.

В первой строке входных данных содержатся два натуральных числа N и K (2 ≤ N ≤ 2000; 1 ≤ K ≤ 2000) — количество зданий промзоны и количество карт соответственно. Вход в промзону находится в здании с номером 1, а склад — в здании с номером N.

В последующих строках находится информация об имеющихся картах. Первая строка описания i-ой карты содержит число ri — количество дорог, обозначенных на i-ой карте. Затем идут ri строк, содержащие по два натуральных числа a и b (1 ≤ a, b ≤ N; a ≠ b), означающих наличие на i-ой карте дороги, соединяющей здания a и b. Суммарное количество дорог, обозначенных на всех картах, не превышает 300 000 (r1 + r2 + … + rK ≤ 300 000).

Выведите одно число — минимальную сумму расходов сталкера. В случае, если до склада добраться невозможно, выведите число –1.

### F Алгоритм Дейкстры за O(M log M)
Сергей Андреевич с Михаилом Сергеевичем часто ездят в разные города мира на конференции по математической кибернетике — науке, которой ещё Яблонский занимался! С недавних пор они решили перемещаться на личном автомобиле Михаила. Ни для кого не секрет, что такие поездки занимают очень много времени, а смартфон при активном использовании Яндекс.Навигатора может разрядиться уже после нескольких сотен километров. Но, как известно, у Ложкина под лысиной функционирует ПЛИСина! Осталось только разработать подходящее программное обеспечение. Но не беспокойтесь, на Verilog ничего писать не придётся, т.к. студенты прошлых лет уже написали полноценный MIPS-процессор, и на нём даже запускается Linux. А недавно, пока Сергей Андреевич спал, Владислав Васильевич собрал на нём самый свежий компилятор gcc.

Вам дано описание дорожной сети мира. Ваша задача – найти длину кратчайшего пути между городами А и B.

Сеть дорог задана во входном файле следующим образом: первая строка содержит числа N и K (1 ≤ N ≤ 100000, 0 ≤ K ≤ 300000), где K – количество дорог. Каждая из следующих K строк содержит описание дороги с двусторонним движением – три целых числа ai, bi и li (1 ≤ ai, bi ≤ N, 1 ≤ li ≤ 106). Это означает, что имеется дорога длины li, которая ведет из города ai в город bi. В последней строке находятся два числа А и В – номера городов, между которыми надо посчитать кратчайшее расстояние (1 ≤ A, B ≤ N).

Вы должны вывести в выходной файл единственное число – расстояние между требуемыми городами. Если по дорогам от города А до города В доехать невозможно, выведите –1.
