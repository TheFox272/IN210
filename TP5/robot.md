# TP5 : Robot

## Syntaxe

avec la commande `ctrl + space`on peut afficher les différents test possible

```
*** Settings ***
Library               RequestsLibrary
Suite Setup    Create Session chuck  https://api.chucknorris.io/
```

>On inclu la library *RequestsLibrary* qui permet de récupérer des requêtes HTML
>l'adresse *https://api.chucknorris.io/* est appelé endpoint
>chuck est le nom de la session

```
affichier une blague
    ${response}  GET On Session  chuck  ${BlagueAuHasard}  expected_status= 200
    Log To Console  ${response.json()}[value]
    Should Contain  ${response.json()}[value]  ${motAVerifier}
```
response.json() permet de convertir la requête en json, avec [value] on récupère juste la valeur de value

