Oliojatko-laajaharjoitus
========================

Tekijä: Mikko Rantala
Pvm: 11.2.2014

== Yleistä ==

Tämä projekti on TTY:n Oliojatko kurssin laajaharjoitustyö, joka on toteutettu C++ ohjelmointikielellä.

Ohjelma itsessään on yksinkertainen jäsenluettelo ja sisältää main-tiedoston lisäksi Jasen, VIPJasen ja Luettelo 
luokat.

== Kääntäminen ==

Käännettäessä projektia tulisi ottaa huomioon se, että lähdekoodissa käytetään unique_ptr toiminnallisuutta, joka
on osa C++11:sta.

== Mahdolliset virheet/puutteet ==

Puute: etu- ja sukunimi syötössä ei ole virheentarkistusta.

== Muistivuodot ==

Ohjelma on käyttää pelkästään C++11 smart pointtereita (unique_ptr), joten muistivuotoja ei pitäisi esiintyä.

DrMemory 1.6.0-2 ohjelmalla testatessa ei löytynyt muistivuotoja.
