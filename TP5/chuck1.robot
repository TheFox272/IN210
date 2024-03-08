*** Settings ***
Library               RequestsLibrary
Suite Setup    Create Session  chuck  ${endpoint}


*** Variables ***
${motAVerifier}  Chuck
${endpoint}  https://api.chucknorris.io
${BlagueAuHasard}  /jokes/random
${categorie}  /jokes/categories

*** Test Cases ***
hello world
    Log To Console  hello world
mot_cle_perso
    afficher  bonjour
    Should Be Equal  bonjour  toto

récupérer une blague au hasard
    ${blague}  récupérer une blague au hasard
    vérifier que la blague contient ${motAVerifier}  ${blague}

récupérer les catégories
    ${cat}  récupérer les catégories
    afficher les catégories ${cat}


*** Keywords ***
afficher 
    [Arguments]    ${var}
    Log To Console    ${var}

afficher une blague
    [Arguments]    ${blague}
    Log To Console  ${blague}

récupérer une blague au hasard
    ${response}  GET On Session  chuck  ${BlagueAuHasard}  expected_status= 200
    RETURN  ${response.json()}[value]

vérifier que la blague contient ${motAVerifier}
    [Arguments]  ${blague}
    Should Contain  ${blague}  ${motAVerifier}

récupérer les catégories
    ${response}  GET On Session  chuck  ${categorie}  expected_status= 200
    RETURN  ${response.json()}

afficher les catégories ${cat}
    @{cat}  récupérer les catégories
    FOR  ${categorie}  IN  @{cat}
        Log To Console  ${categorie}
    END
    
