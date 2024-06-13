## Тестовое задание делалось на ос linux
- тут реализован tcp server и tcp client
- в приложении устройства управления есть графический интерфейс для чтения и записи в регистр
- в приложении устройства реализованы несколько регистров
  Для запуска приложения устройства 
## для сборки g++ -g helllo.cpp ./source/*.cpp -o helllo
приложение для управления устройством использовал qt (для графического интерфейса)
## Вот так оно выглядит
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/fe1225c5-894c-4024-81e8-51e032df3d55)
## Запись в регистр по номеру
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/8d42b624-1db4-4bdd-818d-85176d0678c0)
## В приложении устройства в консоли выведутся запрос и ответ
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/8ebb54ae-e258-4b79-af61-b7ba858259ad)

## Вывод всех значений регистров
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/2c359d08-c827-4197-b741-52cf05429253)
## В приложении устройства в консоли выведутся запрос и ответ
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/ca6a82a8-2801-4a9a-b8c9-0cf5db62c58d)

## Выведется ошибка если ввести не существующий номер регистра при записи (код 0 3 (0x3) )
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/f9fae53b-d726-4fc5-8772-4c371aec9625)
## В приложении устройства в консоли выведутся запрос и ответ
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/023250c1-e65e-48df-8787-c9f80ba4caac)

## Выведется ошибка если пытаться записать в регистр неверное кол во байт (код 0 6 (0x6) )
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/45f1d82c-8a68-4aff-a7c9-ffc1d35ccfb0)
## В приложении устройства в консоли выведутся запрос и ответ
![image](https://github.com/stalkeronag/testtaskcpp/assets/86604604/0434dc05-f3f3-4da2-a5e1-187bf2c0557e)


