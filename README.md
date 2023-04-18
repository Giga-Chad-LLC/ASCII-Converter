# Проект ASCII-Converter

## Участники:
- [Артюхов Дмитрий](https://github.com/dmitrii-artuhov)
- [Артюхов Владислав](https://github.com/Vladislav0Art)

## Задача:

1. Разобраться, как устроен формат BMP-изображений.
2. Научиться работать c BMP-изображениями без использования библиотек.
3. Создание консольной утилиты для конвертации медиа формата (.bmp и/или .bmp со сжатием) в ASCII-графику и сохранения в текстовый файл.

## Сборка:

Сборка проекта осуществляется через `CMake`:
```bash
cd project-root
mkdir ./build
cd ./build
cmake ..
make

# В папке build/ появится executable
```

Чтобы запустить приложение, необходимо подготовить BMP-изображение, имеющее формат **24 бита на пиксель**. Далее нужно запустить executable:
```bash
[exec] path/to/bmp path/to/output/file

# Real example (see 'assets/' directory):
./build/ascii_converter ./assets/sample-1.bmp ./assets/sample-1.out.bmp
```

В случае успеха будет создан файл `path/to/output/file`, содержащий переданное BMP-изображение в виде ASCII-графики.


## Функционал:

1. Реализован BMP-decoder, читающий данные BMP-изображения из файла.
2. Реализован ASCII-converter, который производит преобразование байтов пикселей в ASCII-символы.
3. Реализована консольная утилита, позволяющая создавать ASCII-изображение на основе BMP-изображений.

## Технологии:

- `C++17/20`: язык и его стандарт для разработки.
- Ручная обработка: считывание содержимого BMP-файлов и передача его написанной ascii-утилите для дальнейшей обработки.

## Примеры:

Рекомендуется конвертировать BMP-изображения малых размеров (например, `32x32`, `64x64`), так как сгенерированных для них ASCII-изображения будут достаточно компактными для того, чтобы отправлять их в чаты.

Файлы с примерами можно найти в папке `assets/`.

### Пример 1:
Входные данные (изображение `64x64`):

![Cute anime girl 64x64](./assets/sample-5.bmp)

Результат:
```
................................................................
..........................;Yr(fz?...............................
......................./((((((((()))]...........................
....................x((((((|vczzcr((()(|........................
..................X||||YCCCCCCLCCCCCCCz)))].....................
.................(|||LLLLLLLLLLLLLLCCCCCC|((`...................
...............`|||CLQZQQQQQQQQLLLLLLLLLLLCj(x..................
..............'///|LQQQ00QqQpQQQQQQQQQQLLLQLL||C................
..............?||n1--Unv0p0O0000000QQQQQQQm0LL||r...............
.............[)???Y000000p0wOC0000000000Q0O0QQc||{..............
............/???X0OOmOOOZOwOO0O0qO00}J00000O000/|/~.............
...........X??}OOOOOOOOObOqOOOOOOOOOO0L_000O0000//-.............
...........?]LOZZOOOOZOOpZOZOOOOOOOOOOOZOOOOOOZO0/??............
..........r]OZZZZZZpZZZZZkZZZZpZOZZZZdOdOOOOO?OOO/1?............
..........?nZZZZZZZZZZZmZZZZZZZZZZZkOkZdZZZZZOv?0C/?............
.........`]ZmmmmmmmmZZZpqZZZZmZwZZZZZhwpZZZdZZZO??/?X...........
.........QfmmmmmmmdmmmmphmZmhmmZmZpZZhppZZmhZZZmO????...........
.........{fmwwmmmmwmmmmwammmmmhmmZhZthkpZwmamZmpZZ?]?...........
.........ffmwwwwwwwwmmwmdmmhmawmmdmwthdmmwphhZmwmmZ]]]..........
.........fxwwwwwwwwwwwwqwmkmwammmhZ,faammmmhambmmmmmur..........
.........fJwwwwqwhwwwwwhwwamabmZtmO;/aammmfhomammwwm??..........
.........fOwqqwdqowwwwwowawhLmw,cZ,;(aammZ:vamamwwwmfr..........
.........jwqqqqqqaqqwww*aah,{d;|mm:;|aammZ;tapowwwwwft..........
.........fwqqqqqbhqqqwp*od::w,?fm::;Jawmkr;taoowwwwwff..........
.........jwqqqqq*bqqqqporahhhh/zl;;;qammq:;[hoowwwwwff..........
.........jqqqqqq*dqqqqpOhhqqpbkf~;;;khmwm:;;ho*wqwwwff..........
........`jXqqqqq*dqpqqq,hqwaqw{d:;;;kqm,n+i]aooqbpqwff..........
........~jjqpqpp*pqkqqqIdmwhxZ'~>;;:hZm<?Y:;m[opqoqwff..........
........zrjqpqdk*pqhqqq;lZ+|'Z`:;;;!I,:,;vkhh:aba*qdfj..........
........mrjqdpp:Iqqaqqpl!l[+'`^;;;;;;;;;bpp{hhppo*qpff..........
........mrrphpYi;qqoqqqi>>!mn:;;;;;;;;;:_mw>aaqkbpqq0X..........
........Orrphq:ffdqaqqw><;!l;;;;;;;;;;;,kbw'|>q*#qpqm,..........
........Jcupbq;vmdpaqbw>>>!lI;;;;;;;;;;,+,O`;;p##qqab...........
........cwCppq:;fkpaqbwIiilI;;;;;;;;;;;;(u'II~*##kq}w...........
........nLwppp[;rbpdbdwlllI;;;;;;;;;;r;;IIii!q##*Ip..0..........
........ruppdpqI;UpdopwIII;;;;;;;;;;;p;Ili>>I*##dw.|..;.........
........rjpdddppw:pp#pk;;;;;;;;;;;;;~I;Ili:<-##*rq..............
........rrphddddd#kpMpr:;;;;;;;;;;;;;;;;l!iiw##jJ...............
........rrwMdddkdWddMp|~;;;;;;;;;;;;;;;;Illl*MMj)...............
........r0JMdddddWbdMpYw;;;;;;;;;;;;;;;;;;II#MMr................
........cpd#dddddWMdMkqp;;;;;;;;;;;:;;;;;;;o#WMj................
.......iJnbobbdbdWW#Mjk,;;;;;;;;;;;;;;;;;;,#WWMr................
.......prphbbbbbk&&Wovpj;I;;;;;;;;;;;;;;;,*MWWWj................
.......cxdWbbbbbM*&WawCjjl;;;;;;;;;;;;;;u*MWWWMj................
.......jXdWbbbbbbb&W1prrrjm;;;;;;;;;;;;*MMWWWWMj................
.......Odb&bbbbbbM&W:Irrrrrj;I;;;I;I;*MMWWWWWM!v................
.......1db&bbbbbbW&W;Ilrrrrrrr:I;;;f#MWWWWWWWM..................
......:xdW&bbbkbbW&M;II+rrrrrrrj!;oMWWW&&W&WM#u.................
......Qdb&Wbbb*bbb&MII;IfrrrrrrrMMWWW&&&W&&W..i.................
......rdb&*bbb#bbb&W;I:IIrrrrrrrW&&&W&&&&&Wo....................
......XbW&bbbbkbbbW#--}IlIrrrxr*&&&&W&&&&&o.....................
.....Ukb&&bbbbbbbbbW--_-CIlrxxrW&&&&W&&&&&du....................
.....nbb&&bbbbb*bbb&M---_-iIrr-M&&&&&&&&&&bq....................
....uzb&&&bkbbb&bbbb&#---__cll0XYM&&&&&&&&d-....................
....nab&&&ba*bb#bbbbW&k----_QIqXXXYW&&&8&WdYq...................
...'nbh&&&bbYbbb&bbkb&&h-----IlIzXYYW&888hdk....................
...upbW&&&WdkMbb&bbbab&&d----XlllXXY'&888dhp.w..................
...uldWWWWzwph#doWbbbaa&&L----IllldYp&&88bbd.q..................
..qJ.dWWMrxrnqhhd&kbdbhW&&z---OlIllLYUW&ddbk.q..................
..up.oW*~--??;fdh#&ddbbb&&&---?lll!IYUmWddbd?q..................
..v^.#Zw::::;Y--qM&Wdbbbb&&W???}llIx?--?dbbbba..................
.pp.<h::::iL,::]?,MWkbbbbb&&W???mv--??-?bdbbbd..................
.ud.U:J::::::::,:]-MWddddbb#&#???O??????]bbbbdb.................
.c.{;:;;/:Y:::::[::L*Wdddbbbk&0???Y??????Wbbbbbp................
```




### Пример 2:

Входные данные (изображение `64x64`):

![Cute anime girl 64x64](./assets/sample-7.bmp)

Результат:
```
................................................................
............................'l~l:,i<l...........................
..........................">>'',"`:I">I`........................
........................`>;...``'."^^..!i.......................
.......................">'.........'....,~'.....................
......................Il.................'-'....................
.....................I;...................'+....................
....................,i.............'.......,!...................
....................~'.....'.,`'^..;;.......<'..................
...................>'.....,'`:>:I..i<.:.....'<..................
..................':.....';.l^+-"''+~.>`.....>`.................
.................."'.....l,,i`<?`.^!_'<;.....'<.................
..................;..'..^i'II;~?.'~l<^I>'..'..~.................
..................!..,'^;i,}_Ii_``?;}!!l:..:..<.................
.................,;..;':~i!`lI<>``1i`l-?:`.I..:^................
.................>'.';^"lIl`!>-!'`|!'!<'~:.l..'I................
.................~..:^;I:<'`+I<!'l[i`il`<l.>^..l................
.................<..!'I>,>`"?:~i'>]l^!i`!~'+I..I................
.................>..+'I>;i||_^Il'<-:{1_I<_'-!..;................
.................i..?.I_v{[}j^''``^n}|nc]~.~+..:................
.................>..?.iY:{!i{l'`^`^~r!?_J~.<]'':................
.................l.,+.!x:_vx?'^"^^^_1rn?}<'<]^^,................
.................l.i?'~>^"1)<`","::<Iz{:+~'?-""^................
.................i.i[`+',1i-]`",;:;l(I?-'>`~_,,^................
.................>':-:<..I+>,`,,:;;:>}+^'<:<?,;"................
.................!",<Ii:.'`^^`^,:,:,"^''^?!i~"l:................
.................:l"<Il<'''^`'^^``^```'`<-<+;^;I................
.................:!">-;_''`''''`''`'`'`'~??_I:^I................
.................Il';+,],'''..'..'''`'':?]~>,I"l................
.................l",I!;<_.....!,,l.....?;}i:,l,i................
.................l"l,li>I_....'^,,....{"I]l,"l:!................
.................l,l`:>i"l}'........']+`!<";'i:>................
.................l^<';li`:<?~......;/~i^<l,,.~:i................
................^""<.,I'!'<>-+l..`+l{+I,!:^^.~:>................
................I',>'^,;i^l>[."_?~::([^`l.'..<Ii................
................I.,l'^"l`"`1>'^^",:<_],`I....!;:^...............
...............;'.,!.^',,^^<~'^",",I~+;i'.'..i:'i...............
...............l.',>.^.'l^"II''`^`''[!;i..`'';l.>...............
..............';.""!.^'.`l^l`I....'_'>>^.,.,,`:"!'..............
..............;..,,;'.^..;^;.::..^~`.l>..l.;l.::,`..............
..............I.^>>;,.,...I:..I;:i'..!;.:'';>>,:`,..............
..............+i:...l.'^..l:..<[+1'..>'.I.>'i'i~l'..............
............'+^.....;^.,...>.:?+:]['.I.:^.~'i..'!i;.............
............l`'......!.`^..><{<?,[?_:i.i.;,:,....`>^............
............>.'^.....~;';..,<:[x[j|?{'^;.~.>`'.'i^.~............
............>..`^....>l^"`..!:+1>))__.l`!l.<``'~`..>............
............i...I'...>^_';..l"+{t+~?+.i.+^i""`i:...i............
............l...'l'.'>'+I:..l,<n?]_>I`;I<'(`,;<....i............
............>....I,^,l.~i:'.l;<|+(-]",:_:i<l^_.....i............
............;.....>"`<`i;>,.I^(]__[<',>>`<-!+'.....<............
...........';.....I:..i>?<:'I~+[_<{(`l<!<>^l<......i............
............;......<^...i[+II;i?[![+;!;I!':-'......!............
............;......<"..`_I~~i!;_^?<+iI;~]'>l.......i............
............i......'>..[iI~>i;;+.[+><;;?~I-........i............
............i.......l.`,;~ii!"+I'{>i-;,[][:.......;`............
............!.......'`.>.^I;>^+;,-~l<;l];]........>'............
............i........".!^I>^[>i,l~}i]!<+-!........>.............
............!........l..?>I^<'i;+~<>`+l__".......`i.............
............i........`;.'+I^>.>,`<'.;!~'>........>'.............
............,`........_..'],i.>^;^'.!>,'i........>..............
............'l........<,..`i>`^!<''`<+.I'........>..............
.............l........!,'..I!I']~',?~''-........`l..............
.............!........`:,'.'Iii|>^~''::>........>'..............
.............;^........>`'.^',l~'~',;.!"........<...............
```




### Пример 3:

Входные данные (изображение `64x68`):

![Cute anime cat 64x68](./assets/sample-8.bmp)

Результат:
```
................................................................
.....'Lx~`...............`![[!^l_~".............................
.....]J(YdZv+`.....^<{rUmpLvvLqZYCwqr+:.........................
.....j(.!i>)Qdn_`fwbLn)~,..........,1X0wu?'.....................
.....n1;nnr],lmbLY<`...................;(0L,....................
.....n1>nnnnnYkU}........................./p-...................
.....X[?nnnvpp+............................!mr..................
.....U[)nnLhU,..............................^C/.................
.....L<)vqw>................................."Cc`...............
.....U+1pL,...................................'uLl`.............
.....r(rO"......................................ubw0j+'.........
.....}wpl.........................................."}vZj_'......
.....io1..............................................^]vq0r<'..
.....<k`...........................................l[-!`.^<xpL+.
.....ur............................................lrnnx)+I'.rb`
....,b".............................................:nnnnnnt'J+.
..../v...............................................1nnnnnf!m..
....O+...............................................lnnnnn+/f..
...lp'...............................................lnnnnt'Y_..
...)v................................................'jnnnilh"..
...U?........1X_'.....................................1nn}'cC...
...ml.......{ooau.............`jZOt`..................int'/O"...
...ml......'dooob.............zoooov..................'{;)O`....
..:p-...^"``aooob....!X^.....'aooooa,...................10".....
.'XYI..";;;`Joooc."()0Zpjl,...dooooa^.`'..............'}Z,......
.<q,^..,;;;^"rXt^.IvzZXUdwz...?qaohj.:;;:'...........`"O-.......
.fr"'..`;;;'........^qXXm.......",`.^;;;;:..........'",b:.......
.c{"....`^'..........CXXd:..........`;II;;..........`"!Z`.......
.Y[".................)QXq~...........,;;;^..........^"~L'.......
.J]"'................"ZXZ]............`^'...........^"_J........
.X{"'.................JXq+..........................^"-C........
.jf"`.................(Jp^..........................^"}Y........
.1v"^.................`Ur...........................""(x........
.<L""^.............................................^""Y}........
.^bI""'...........................................`""id^........
..vj""^..........................................`"""cf.........
..ld,""`........................................`"""~p".........
...Yr"""`.....................................'`""";p)..........
...:q)"""`..................................`^"""",XL'..........
....IZUI""^^^`............................`""""""?LJ`...........
.....'rbv?,"""^'..............I?]-!'....'""""",{OO1'............
.......:/Lqr/{{z`............_ut((rj!''i:l{}/cqc~...............
.........'~/vLkY"...........]n?__++{u};mqZd0j]^.................
.............{z""..........:u-_++++_?x~...1r....................
............'m~"`......`'..<j+___?[_+]n"..;w....................
..^__,......}U""'......X0>.-f__-?-1]?_|c<..Z;...................
.}bCLd|....'q<"^.......`{dv|zz|?1{1{?_nQi..v]...................
'w?""<w('..]U""`.........luZCXdv{?-}+_0?..^Ot...................
;d""""lOf..X]""`..............<k{}_{}?w~..!ov...................
`pr[:""iq-'q:""'..............;w11{1}_0]..)zd,..................
.lxLb)""+p+O"""...............?Z{{]-1_rm<lZ!rv..................
....ip?""jqQ""^......^z-l,;<{vZn+??_-_|/mwj.^w~.................
....'-w,",OO""`......`xYOZOJv(|r-+__+?u".....<ql................
.....^J}""?m""`...............!)x{{]_|t,......-q_...............
......?L,"~m""`................`~fc(_{ut,......>mu^..`^'........
......"w}";k,"^.................`[r-u1?n_.......,UQ-^:::^'......
......:{p!"O-"^..................}j{xxru;.........]LCl;;;;'.....
.....`;;jQ;nj,"..................Irn>,<;'''''''''.."m?;;;;:'....
.....';;IJmrQ;,`...................'.'^""""""""""",:X|;;;;;^....
......:;;Ifk0I:"`.................IL,^"""""""""",;;!Q/;;;;;,....
......";;;;~kz:""`................^CaZ+,1zZpqwZZwqdkUl;;;;;:....
......`;;;;;[b]:""^.................IXkwQ(_!><<illl;;;;;;;;:....
.......:;;;;;?b/;"":,^``''''..........ja);;;;;;:;;II;;;;;;;^....
.......`:;I;;;]qpn~;:""""""""""""^^^^`"0pI;;;;II;;;;;;;;::".....
........`:;;;;;irZhQvf1_l""""""""""""",th;;;;;;;;::,^`''``......
.........^,;;;;;;;>]xqaookqZQYcr1-~iIl]qZ;;;;;;:"^'.............
..........^,:;;I;;;;;;l?(/{][)/nUdaoooohf;;;;;:`................
...........^"",:;;;;;;;I;;;;I;;I;I<_[|{i;;;;;:^.................

```



### Пример 4:

Входные данные (изображение `100x40`):

![Bunch of cute cats 100x40](./assets/sample-9.bmp)

Результат:
```
................................................................................`un/11/nz/^.........
................................................................................r`..,....:x/........
................................................................................r..|Jt.....<f.......
...............................................................................;?..JjJfCJ-..r.......
...............................................................................]:..Cjnvjjx..f.......
.............................................................................../...Xjjjjz]..x.......
...................._f|(f!.....................................................j...fjjjv(...r.......
..................>f:.^^./.....................................................r...+vjz[...!_.......
.................!_;j[zv.].....................................................r....YX_....j........
.................].-rvjx.l;....................................................[~.../>....`r........
.................i:`vjr?.^<.....................................................(r........r"........
..................}.!uv'.;!......................................................f}ccvxjjv+.........
..................|..<1.`r.......................................................f|.................
........}r/..>....ii..i/)'.......................................................'..................
..^^...+j}}j.<./<..~fjl..!...............................l........iu,..........................,....
..ttl../?(/Xi.j,t....]..`Br.................>...........|Y".......t.x.............<;..........iX}...
..f.1i.[]]}u./:.f.......[$$[........._U.....pJ`........}r/]......./.^/........:rr.f{~..."....;z|r...
../..}fufctvrl..(.......z$$8l;i;.,:1j@B....,pm0,.;]11??u||f......,_..<jfff(;.-1.f./._].({f(}>X||c...
..|....?"],[`...]'......p$$$$$$$@wq0$$$....lqmmmZpf||/r|||u......[`........+r>..f.(;~|O+>|||x|||z...
..1....~`~'+....i!......B$$$$$$$$Zcp$$$....>qmmmmm-(||||||z......x..............f.1}<?{(]|f|||||u,..
.:-....`.........x'....j$$$$$$$$$$d@$$$....~wmmmmO^<||||||n~....r`..............f.}]<_)!:;||||||t)..
.r...............`/...{$$$$$$$$$$$$$$$@....1mmmmm{..l])||||c;..1,...............f<>-}~....:-)||||n<.
?:................[,.,8$$$$$$$$$$$$$$$${..^UQmmU]......'^,,,r.`)................}f.."........'":;;j.
f.....`......;`....(.u$$$mQ%$$$$$$$$$$$#'./..'........."l^..>!}`.................{...........`l"..,}
{...>{j>....)/(|...f.o$$Q}M*$$$$$$8wM$$$[./..^]j".....^Q&(`..|f..."|'............}.`]zi.....`n8j^..r
~...j"`j....(..).../^$$$t%$$@$$$$@u8rW$$X,_..+r$Z.....fM$O;..ff`..+0d}...........?^>fBM'....]o$k!..|
<...~..~....l..".,;tl$@$r8$@$$$$$@%$q0$$mil..1$$8.....1$$C:.`tf;;....'.....I<?'..>I+@$$,....<$$ql..1
[~`......'.......>If,$B$ouq&$$$$$B$$Qw$$q!!..~o$0......vQ+.l,fti,..........|Cp:..~:!Z$q......jm}';l/
r/^......(i......;<?.aB$$$$$$$@$$@p0r@@$L`[<^`~1^..!I...'..I!(l/`......}>......;l},.l-^..I>...'..,ir
(,-.....l+i:.....'u..)$$$$$$$$&$$$$W$$%$/.j>"......>l......,u^.|;......l.......I;c[i.....,~......,/i
{>-'............lr`...Y$$$$$$$$$$$$$$$B&^.>(,......''......}<...1}.............i1n"]......`......<{.
(l`u[,......'!}n_......(8$$$$$$$$$$$$$B]...]}............~XI.....j1{I..........{_)_il..........Ir~..
[..t]-}}}}}}}i.^}......`%$$$$$$$$$$$$p~.....:ft?!:,;>]1fcxvI.....|..~{{{{[-?}t/,.)'.x}_!Il<?{{{~t...
'?.<^..........~u......{$$$$$$$$$$$$p.........u?|+_~l`'](j(r....ii.......`,^.<I..?.._.,i<>I^...^{{..
.1............_'I).....C$$$$$$$$$$$$&........{'.~........+.')...(............`[..`+.>.........._.,).
.'[...........~"'-.....*$$$$$$$$$$$$$`.......(I_[........?!!|...f.............(...(............+:`}.
..?^..........l{}j....,$$$$$$$$$$$$$$,.......?-!.........,+r....f............./...+`...........l[/-.
...v'............|....+$$$$$$$$$$$$$$:.......]`............~,.../............./....1.............,_.
...|^......`::l>i?....'!?(nJma%$$$$$$,.......<>~<+~~<i!;,`......'";li>~<+~~<ii{...._;.......:i~~>I`.
...>!;:^.......................,<{rUw^.............................................']:i~<!^.........
```



### Пример 5 (damn, we love it!):

Входные данные (изображение `44x77`):

![F*ck 44x77](./assets/sample-6.bmp)

Результат:
```
.................&kq&.......................
................W<i~-%......................
................l%(<<{Z.....................
...............W+>>--oW.....................
...............&{>>--&M.....................
...............W!><--p].....................
...............M>W>~%-+.....................
...............%>~#&j--.....................
...............B>>>_--?.....................
...............%>>>~--?.....................
...............%>>>---?.....................
...............%>>>--??.....................
...............*>>>--?-.....................
...............C>>>--_+.....................
...............n>><---+.....................
...............w>><---_.....................
.........``....%>>>---?.....................
........&<?....W>>>----.....................
.......pi-ft...W>>>----^....................
......Y8>-fW...8>/&8&]?[.'..................
.....n~8-(f8...8>+|||-(Wn~hW................
....M8[~-ff#.8%M>>>?__fWfft?Xj..............
...8f]---f{&d+_&>>>--_fMffff[_`.............
..W?----{&>>>_?&>>>>--f8fffff-W&&...........
.i<<>--_M<>>>-fW>>i>--jofffff-%f?#I.........
>q>>>--_W>>>~-fW>>>>--fpfffff-Mff/>&........
W>ii>+_]Q>>>--t&>>>>--f#ffff--Lfff-M........
&>>>~-?t{>>>--)%>>>>--f%ffff--]fff-<1.......
&i>-OM8#l>>>+-]%>>>>--f&fff---+fff--8.......
&>><+?&U<>>>+-?%>>>>--f&fff----fff--8.......
b>>>---8>>>>+--&>>>>--?&ff[_>--hff--~'......
z>>>>--&>>>>--]8>>>>+--fff->>--Wff---&......
v>>>~--*>>>>--tp>>>>+--1tf->>--&jf---d......
W>>~--U]>>>>--ti>>>>~--t&f->>_-]*f_~>-`.....
W>>#-8ai>>>i--O<>>>>~--foQ->>---rf->>-%.....
&>>W--&>>>>--t&>>>>>~--ftf+>>---ff->>--.....
&>>-%f8>>>>--+z>>>>>+--jff->>---ft->>_-J....
0>---xl>>>>~-r->>>>>---fff->>---f-_>>---&...
.&--/&>>>>>---->>>>>---fff->>---f-->>-?f-W..
..8fjL>>>>----->>>>>--{fff->>---f-_>>--f-&..
...M#>>>><----->>>><--ffff->>---f--~>-{f-a..
....8>>>>------>>>>---ffff->>---f_-~-_/f{t..
....8>>>--j---->>><--}ffff-<>---ffffzxfff>..
....Wf----(----->~----ffff-----nfffffffff--.
.....8)fff#t----------fffff[Z-&ffffffffff1*.
......M_fffff{--{8/ttxffffffftffffffffffff+.
.......&_fffffffffp8ffffffffffffffffffffff-m
........&]ffffffffffffffffffffffffffffffff-W
.........&]fffffffffffffffffffffffffffffff-&
..........&?ffffffffftffffffffffffffffffff-&
..........^W_fffffffffffffffffffffffffffff-&
...........'&-ffffffffjfffffffffffffffffff?W
............'W_ffffffffffffffffffffffffff?~p
..............&#[fffffff&ffffffffffffffff-W.
................WwfffffffUfffffffffffffff?^.
.................'&&o(fff/tfffffffffffff-W..
.................'*8&fffffffffffffffffffc&..
..................1+)|b%aJ/ffffffffffff+jM`.
...................#+-fffffffffffffffffff_i.
...................&>>+-(ffffffffffffffff-{.
...................f>>>><_-tfffffffff?fff-C.
...................l>>>>>>>----{fff}--fff-b.
....................i>>>>>>>>~--------fff-o.
....................!>>>>>>>>>>>-----?fff-#.
...................'<>>>>>>>>>>>>----/fff-W.
....................i>>>>>>>>>>>>>---ffff-&.
..................."!>>>>>>>>>>>>>---ffff-8.
..................._i>>>>>>>>>>>>>---ffff-8.
...................Y>>>>>>>>>>>>>>--/ffff-W.
...................&>>>>>>>>>>>>>---fffff-W.
...................M>>>>>>>>>>>>>---fffff?[.
...................b>>>>>>>>>>>>---?ffffft(.
...................ii>>>>>>>>>>~---ffffff8..
.....................'8i>>>>>>>----ffff/W...
........................W!>>>>-----fff8u....
.........................`Mvi----_fm&8......
............................pWW&W&8[........
```