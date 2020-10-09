# import googletrans
# print(googletrans.LANGUAGES)
# -*- coding: utf-8 -*-

'''manual-source expluatation of google translator api: https://dev-gang.ru/article/perevod-teksta-s-pomosczu-google-translate-api-v-python-ahgm88wx1k/'''
from googletrans import Translator, LANGUAGES
import os

translator = Translator()
result = translator.translate('Mikä on nimesi', src='fi', dest='fr')
# print(result.text)


'''
В приведенном выше сценарии мы передаем финский текст методу translate().

Метод translate() возвращает объект, содержащий информацию
о переводе текста, источника и назначения языков и произношения текста.
По умолчанию метод translate() возвращает английский перевод текста, переданного ему.
В нашем случае объект, возвращаемый методом translate(), сохраняется в переменной result.

Объект, возвращаемый методом translate(), имеет следующие атрибуты:

src: Исходный язык
dest: Язык назначения, установленный на английский (en)
origin: Оригинальный текст, в нашем примере это Mitä sinä teet
text: Переведенный текст, в нашем случае это будет «what are you doing?»
pronunciation: Произношение переведенного текста
Давайте напечатаем все вышеперечисленные атрибуты и посмотрим, что мы получим
'''


# print(result.src)
# print(result.dest)
# print(result.origin)
# print(result.text)
# print(result.pronunciation)


# with open('this.txt', 'r+') as f:
#     res=translator.translate(f.read(), src='en', dest='ru')
#     f.write('\n'+'='*16+'\n'+res.text)

# with open('this.txt', 'r+') as f:
#   l=f.readlines()
# with open('this.txt','w') as f:
#   for i in l:
#     res=translator.translate(i)
#     f.write(f'{res.origin} -> {res.text}\n')


class Max_Translator:
    def __init__(self, src='en', dest='en', s=' ', lng=False, interface='en') -> object:
        self.src = src
        self.dest = dest
        self.s = s
        self.result = ''
        self.spl = LANGUAGES
        self.lng = lng  # shows result in src: origin -> dest: text format
        self.interface = interface  # lang of lang menu

    def quick_trans(self, s):
        # if lng=='':
        #     lng=self.interface
        tmp = translator.translate(s, dest=self.interface)
        return tmp.text

    def translate(self):
        # self.s=input()
        if self.src == '':
            r = self.translate_from_undetected()

        else:
            x = translator.translate(self.s, src=self.src, dest=self.dest)
            if not self.lng:
                r = f'{x.origin} -> {x.text}'
            elif self.interface == 'en' and self.lng:
                r = f'{x.src}: {x.origin} -> {x.dest}: {x.text}'
            else:
                tmp_src = self.spl[self.src]
                tmp_dest = self.spl[self.dest]
                tmp_src = translator.translate(tmp_src, dest=self.interface)
                tmp_dest = translator.translate(tmp_dest, dest=self.interface)
                r = f'{tmp_src.text}: {x.origin} -> {tmp_dest.text}: {x.text}'
                del tmp_src, tmp_dest
            self.result += r + '\n'
        return r

    def write(self):
        return self.result

    def file_write(self, clean=True):
        if clean:
            os.system('cls||clear')
        with open('result.txt', 'a') as f:
            f.write(self.write())

    def translate_from_undetected(self) -> object:
        x = translator.translate(self.s, dest=self.dest)
        r = f'{x.src}: {x.origin} -> {x.text}'
        self.result = r + '\n'
        return r

    def supported_languages(self, pr=True):
        self.file_write()
        os.system('cls||clear')
        if self.interface == 'en':
            rt = '\n'.join([f'{i} : {self.spl[i]}' for i in self.spl])
        else:
            rt = '\n'.join([f'{i} : {self.quick_trans(self.spl[i])}' for i in self.spl])
        if pr:
            print(rt)
        return rt

    def change_interface(self):
        tmp=self.interface
        self.interface=''
        while (self.interface not in self.spl.keys()) or self.interface == 'en':
            self.interface = input('Which interface do you prefer(help to see all supported): ')
            if self.interface == '' or self.interface == '\n' or self.interface == 'en':
                self.interface = 'en'
                break
            elif self.interface == 'help':
                self.interface = 'en'
                print(self.supported_languages(pr=False,))


if __name__ == '__main__':
    tr = Max_Translator('ru', 'en')
    tr.change_interface()
    while 1:
        tr.s = input(tr.quick_trans('input your word or some operation: '))
        if tr.s == 'q' or tr.s == 'quit' or tr.s == 'exit':
            tr.file_write()
            del tr
            break
        elif tr.s == 'en' or tr.s == 'англ':
            tr.file_write()
            tr = Max_Translator('en', 'ru')
        elif tr.s == 'ru' or tr.s == 'ру' or tr.s == 'russian':
            tr.file_write()
            tr = Max_Translator('ru', 'en')
        elif tr.s == 'all languages' or tr.s == 'all':
            tr.supported_languages()
        elif tr.s == 'undetected to english' or tr.s == 'ute':
            tr.file_write()
            tr = Max_Translator(lng=True)
        elif tr.s == 'undefined to custom destination language' or tr.s == 'utc':
            tr.file_write()
            tr = Max_Translator(dest=input('destination language to translate from undetected: '), lng=True)

        elif tr.s == 'change interface' or tr.s == 'ci':
            tr.change_interface()
            os.system('cls||clear')

        elif tr.s == 'change src and destination languages' or tr.s == 'выбрать язык' or tr.s == 'mch':
            tr.supported_languages()
            tr.file_write(False)
            tr = Max_Translator(src=input('source language: '), dest=input('destination language: '), lng=True)
            os.system('cls||clear')
        elif tr.s == 'cls':
            os.system('cls||clear')
        # elif tr.s== 'by' or tr.s=='bel'
        elif tr.s == 'help':
            print(tr.quick_trans(
                f'''
|это программа переводчик для консоли написанная by Maxim Syromolotov 18 y.o. developer
|               LinkedIn:   {f'https://www.linkedin.com/in/maxim-syromolotov-1892421b2/'}
|               GitHub:     {f'https://github.com/Max-Sir'}
| 
|
|       По умолчанию стоит перевод с англиского на русский язык
|------> что бы сменить языковую пару введите команду {f'change src and destination languages'} или {f'mch'}
|                или {f'выбрать язык'}
|
|
|-> для быстрого перевода с английского на русский введите команду {f'en'} , или наоборот {f'ru'}  -
|       для обратного перевода.
|->   {f'change interface'} или {f'ci'} - для смены оболочки на ваш предпочетаемый или родной язык.
|-> для просмотра всех доступных язаков наберите команду {f'all'} или {f'all languages'}.
|-> для очистки консоли введите: {f'cls'}
|-> для перевода с незнакомого вам языка на английский {f'undetected to english'} или {f'ute'}.
|-> а с незнакомого вам языка на выбранный вами  {f'undefined to custom destination language'} или же {f'utc'}
|-> для вызова меню помощи команда {f'help'}
|-----> для выхода {f'quit'} или {f'q'} или {f'exit'}

                '''
            ))
        else:
            print(tr.translate())


'''
08.10.2020 исправить help->ci->help->... не меняется язык вывода
'''
