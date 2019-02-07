//
//  dictionarylib.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "dictionarylib.h"

/* - inizializzazione struct - */

static wordstruct dictionary_words[] = {
    
    
    /* Lettera A: indice  - 1 - */
    { a,"abbassare", "calare, far scendere, spostare verso il basso", { "alzare", "far salire", "innalzare" } },
    { a,"abbellire", "adornare, ornare, rendere più bello, decorare, arricchire, impreziosire, guarnire, ingentilire", { "imbruttire", "deturpare","rovinare" } },
    { a,"abbastanza", "sufficientemente, quanto basta, a sufficienza, bastantemnte", { "troppo poco", "insufficientemente", "scarsamente" } },
    { a,"abbandonare", "lasciare, lasciare da parte", { "cessare", "lasciar perdere", "rinunciare", "dimettersi", "abdicare" } },
    { a,"abbinare", "unire, congiungere, accostare, riunire", { "separare", "dividere" } },
    
    
    /* Lettera B: indice  - 2 - */
    { b,"baccano", "chiasso, fracasso, frastuono", { "silenzio", "calma", "tranquillità"} },
    { b,"banale", "privo di originalità, distinzione, importanza", { "elegante", "affascinante","straordinario", "particolare", "insolito" } },
    { b,"barbaro", "appartenente a un mondo che è lontano dal nostro modo di vivere e di pensare", {"mite", "generoso", "cortese"} },
    { b,"barboso", "una persona considerata pesante e monotona", {"divertente", "piacevole", "simpatico", "allegro", "interessante"} },
    { b,"basico", "qualcosa ritenuto fondamentale, di base", {"accessorio","avanzato", "superiore"} },
    
    
    /* Lettera C: indice  - 3 - */
    { c,"cadaverico", "pallidismo a causa di un cadavere o perdita notevole di sangue", { "colorito", "roseo", "rubicondo", "fiorente"} },
    { c,"cafone", "una persona dai modi villani", { "gentlemen", "gentiluomo", "signore", "persona fine" } },
    { c,"cagionevole", "di costituzione molto debole, predispost ad ammalarsi", {"sano", "robusto", "florido", "resistente"} },
    { c,"calmare", "ridurre alla calma, placare", {"eccitare", "irritare", "innervosire", "stimolare", "fomentare"} },
    { c,"cancellare", "coprire una scrittura in modo da renderla illeggibile", {"conservare", "tenere", "salvare"} },
    
    
    /* Lettera D: indice  - 4 - */
    { d,"debito", "Imposto da leggi o consuetudini o richiesto dalle circostanze", { "credito", "attivo", "libero", "volontario"} },
    { d,"debole", "scarso o privo di forza fisica", { "forte", "robusto","vigoroso","energico" } },
    { d,"decelerare", "rallentare,diminuire la velocità, andare più piano", {"accellerare"} },
    { d,"decentrato", "periferico,non centrato", {"centrale", "centralizzato", "accentrato", "centralistico" } },
    { d,"deciso", "agisce con prontezza, energia e sicurezza", {"indeciso", "incerto", "dubbioso", "odscillante", "titubante" } },
    
    
    /* Lettera E: indice  - 5 - */
    { e,"eccelso", "fuori dal comune, sommo, sublime, eminente", { "infimo", "inferiore", "pessimo", "di basso livello" } },
    { e,"eccesso", "superamento del limite consentito o tollerato", { "moderazione", "misura","equilibrio", "rispetto" } },
    { e,"eccezionale", "qualcosa di straordinario o unico", {"usuale", "solito", "quotidiano", "comune", "regolare"} },
    { e,"economico", "poco costoso, abuon mercato spesso associato a qualcosa di scadente", {"costoso", "caro", "dispendioso", "lussuoso" } },
    { e,"educato", "che si comporta con civiltà e cortesia", {"maleducato","incivile", "screanzato", "villano", "cafone"} },
    
    
    /* Lettera F: indice  - 6 - */
    { f,"facile", "che non chiede alcuna dote o applicazione particolare", { "difficile", "arduo", "difficoltoso", "complicato", "complesso"} },
    { f,"facoltativo", "non obbligatorio", { "obbligatorio", "necessario", "forzato", "inevitabile", "indispensabile" } },
    { f,"falso", "contrario o non corrispondente al vero", {"vero", "genuino", "autentico"} },
    { f,"famoso", "universalmente noto perl'eccezionalità degli aspetti positivi o negativi che presenta", {"sconosciuto", "ignoto", "oscuro", "anonimo", "dimenticato"} },
    { f,"fantasioso", "Dotato di fervida immaginazione", {"realista", "reale", "concreto"} },
    
    
    /* Lettera G: indice  - 7 - */
    { g,"galantuomo", "persona onesta per bene, gentiluomo", { "malfattore", "furfante", "deliquente", "disonesto", "canaglia"} },
    { g,"geloso", "tormentato dalla gelosia", { "indifferente", "fiducioso", "sicuro", "certo", "sereno" } },
    { g,"generico", "che non si fonda su particolari noti o concreti", {"detttagliato", "particolare", "unico", "specializzato", "personale"} },
    { g,"genio", "disposizione naturale spiccata, attidudine o talento", {"stupido", "sciocco", "nullità", "zero" } },
    { g,"gigante", "uomo fornito di talento eccezionale, che domini incontrastato in un dato campo o epoca", {"uomo comune","piccolo", "minuscolo"} },
    
    
    /* Lettera H: indice  - 8 - */
    { h,"handicap", "penalizzazione, svantaggio", { "vantaggio", "facilitazione", "aiuto", "agevolazione"} },
    { h,"hardware", "materiale elettronico come elaboratori, calcolatori, unità fisiche", { "software" } },
    
    
    /* Lettera I: indice  - 9 - */
    { i,"ibrido", "individuo animale o vegetale proveniente da un incrocio di genitori appartenenti a razze diverse", { "puro", "di razza", "omogeneo"} },
    { i,"igienico", "rispondente a determinate esigenze e prescrizioni dell'igiene", { "antigienico", "sporco", "infetto", "malato", "nocivo" } },
    { i,"ignoto", "non cnosciuto ne identificato o identificabile", { "famoso", "noto", "celebre", "conosciuto", "popolare" } },
    { i,"illeggibile", "di difficile o impossibile decifrazione, indecifrabile", {"leggibile", "comprensibile", "decifrabile" } },
    { i,"illogico", "qualcosa di irragionevole o assurdo", { "logico", "ragionevole", "sensato", "ragionevole" } },
    
    
    /* Lettera J: indice  - 10 - */
    { j,"junior", "minore o persona giovane", { "senior", "anziano", "maggiore"} },
    
    
    /* Lettera K: indice  - 11 - */
    { k,"killer", "assasino, sicario che uccide a pagamento e non", { "difensore", "tutore", "protettore", "salvatore"} },
    
    
    /* Lettera L: indice  - 12 - */
    { l,"laborioso", "che presenta notevoli difficoltà, superabili soltanto con sforzo e assidua applicazione", { "facile", "semplice", "rapido"} },
    { l,"lagnoso", "chi è solito lamentarsi di tutto", { "contento", "soddisfatto","appagato", "compiaciuto" } },
    { l,"lascivo", "sensuale o lussurioso", {"pudico", "verecondo", "morigerato","costumato", "casto"} },
    { l,"leale", "persona fedele, devota e sincera", {"infedele", "ingannevole", "falso", "insicero", "traditore"} },
    { l,"legale", "conforme alla legge", {"illegale", "illecito", "proibito", "vietato" } },
    
    
    /* Lettera M: indice  - 13 - */
    { m,"macchinoso", "qualcosa di complicato o complesso", { "semplice", "chiaro", "agevole", "lineare"} },
    { m,"macchiavellico", "persona opportunista,astuta,furba", { "leale", "corretto", "onesto", "chiaro", "franco" } },
    { m,"maestoso", "qualcosa di solenne o superbo", {"modesto", "umile", "semplice", "dimesso"} },
    { m,"maggiore", "più grande in senso proprio", {"minore", "piccolo", "inferiore", "secondario", "meno importante"} },
    { m,"maggiorenne", "persona che ha raggiunto l'eta' maggiore", { "minorenne", "minore", "piccolo"} },
    
    
    /* Lettera N: indice  - 14 - */
    { n,"nascosto", "qualcosa di occultato, segreto", { "evidente", "aperto", "scoperto", "chiaro", "esplicito"} },
    { n,"nauseato", "persona disgustata, stomacata", { "desideroso", "voglioso","ingordo", "appetente", "avido" } },
    { n,"nebbioso", "pieno o coperto di nebbia", {"chiaro", "preciso", "evidente", "lineare", "nitido" } },
    { n,"necessario", "qualcosa di importantissimo, insdispensabile", {"superfluo", "inutile", "futile", "vano", "accessorio"} },
    { n,"negare", "smentire, dire di no", { "affermare", "approvare", "accordare" } },
    
    
    /* Lettera O: indice  - 15 - */
    { o,"obbligatorio", "previsto e imposto per legge o da altre disposizioni normative", { "facoltativo", "libero", "opzionale"} },
    { o,"obeso", "persona affetta da obesità", { "snello", "secco", "gracile", "magro", "esile" } },
    { o,"occasionale", "incidentale, imprevisto, inatteso", { "voluto", "cercato", "provocato" } },
    { o,"occupato", "persona assorbita dai doveri che limitano interruzioni o distrazioni", {"libero", "indipendente", "sgombro", "disoccupato" } },
    { o,"odioso", "persona detestabile, ripugnante", {"amabile","caro", "simpatico", "gradito"} },
    
    
    /* Lettera P: indice  - 16 - */
    { p,"pacifico", "persona calma e pacata", { "bellicoso", "violento", "guerresco", "battagliero", "attaccabrighe"} },
    { p,"paesano", "del paese,del luogo,nostrano", { "forestiero", "straniero" } },
    { p,"paladino", "cavaliere, guerriero, compione o eroe", { "nemico", "avversario", "oppositore" } },
    { p,"palese", "qualcosa di evidente e visibile", {"nascosto", "occultato", "celato", "segreto", "oscuro"} },
    { p,"pallido", "sbiancato nel colorito", { "colorito", "rubizzo", "sano", "sgargiante" } },
    
    
    /* Lettera Q: indice  - 17 - */
    { q,"qualificabile", "riconducibile a caratteristiche definite", { "inqualificabile", "indefinibile" } },
    { q,"qualunquista", "seguace del movimento politico del qualunquismo", { "attivista", "impegnato" } },
    
    
    /* Lettera R: indice  - 18 - */
    { r,"rabbioso", "persona adirata e arrabbiata", { "calmo", "sereno", "pacato", "tranquillo", "quieto"} },
    { r,"raccomandabile", "persona o servizio consigliabile e affidabile", { "sconsigliabile", "poco raccomandabile", "inaffidabile" } },
    { r,"radicale", "drastico, risolutivo, definitivo", {"superficiale", "epidermico", "leggero", "blando", "conservatore" } },
    { r,"radioso", "esaltato da una prorompente e diffusa luminosità", {"nebbioso", "offuscato", "coperto", "opaco", "oscuro"} },
    { r,"raffinatezza", "distinzione per eleganza e gusto", { "volagarità", "rozzezza", "grossolanità", "sciatteria", "maleducazione" } },
    
    
    /* Lettera S: indice  - 19 - */
    { s,"sabotatore", "guastatore, persona che ostacola e disturba", { "collaboratore", "sostenitore", "fautore"} },
    { s,"saccente", "che ostenta in modo irritante un'erudizione o una cultura piu' presunta che reale", { "modesto", "umile","riservato", "semplice", "senza pretese" } },
    { s,"sacro", "religioso,culturale,liturgico", { "profano", "demoniaco", "diabolico", "maledetto"} },
    { s,"sadico", "persona crudele, atroce e perversa", { "masochista", "sensibile", "delicato", "angelo", "santo"} },
    { s,"saggio", "che nell'agire e nel parlare dimostra prudenza", {"stolto", "stupido", "imprudente", "sprovveduto", "avventato"} },
    
    
    /* Lettera T: indice  - 20 - */
    { t,"taccagno", "persona avara e spilorcia", { "generoso", "prodigo", "largo", "splendido", "mecenate"} },
    { t,"taciturno", "persona silenziosa", { "loquace", "rumoroso", "chiacchierone", "espansivo", "estroverso" } },
    { t,"talento", "capacita', bravura", { "incapacita'", "inettitudine", "indifferenza", "indisposizione", "inetto" } },
    { t,"tecnico", "persona tecnologica", {"culturale", "umanistico", "inesperto" } },
    { t,"temibile", "pericoloso o inquietante", { "innocuo", "provvidenziale", "benfico" } },
    
    
    /* Lettera U: indice  - 21 - */
    { u,"ubbidiente", "che esegue prontamente gli ordini ricevuti", { "disubbidiente", "indisciplinato", "ribelle", "inadempiente", "insofferente"} },
    { u,"ubriaco", "persona soggetta agli effetti dell'alcol", { "sobrio", "astemio", "lucido" } },
    { u,"ufficiale", "di documento o notizia proveniente dall'autorita' competente", { "ufficioso", "confidenziale", "privato", "incerto", "approssimato" } },
    { u,"uggioso", "tempo grigio e nuvoloso", { "soleggiato", "bello", "sereno" } },
    { u,"uguale", "identico o indistinguibile", { "diverso", "differente", "disuguale" } },
    
    
    /* Lettera V: indice  - 22 - */
    { v,"vago", "cqualcosa di impreciso o indefinito", { "preciso", "definito", "nitido", "chiaro", "netto" } },
    { v,"validità", "qualcosache ha valore", { "invalidita'", "nullita'", "inefficacia" } },
    { v,"vandalico", "persona distruttiva e devastatrice", { "costruttivo", "protettivo", "conservativo", "civile", "pacifico" } },
    { v,"vanitoso", "che fa di tutto per mettere in mostra le proprie qualita' fisiche", {"modesto", "umile", "semplice", "dimesso", "serio"} },
    { v,"variopinto", "policromo, multicolore", { "monocolore", "a tinta unita", "monocromatico", "uniforme" } },
    
    
    /* Lettera W: indice  - 23 - */
    { w,"watusso", "gigante, granatiere", { "nano" } },
    
    
    /* Lettera X: indice  - 24 - */
    { x,"xenofobo", "razzista, sciovinista", { "esterofilo", "tollerante" } },
    
    
    /* Lettera Y: indice  - 25 - */
    { y,"yankee", "unionista, nordamericano", { "confederato", "sudista" } },
    
    
    /* Lettera Z: indice  - 26 - */
    { z,"zelo", "premura, diligenza o attenzione", { "negligenza", "svogliatezza", "apatia", "indolenza", "pigrizia" } },
    { z,"zitto", "silenzioso o taciturno", { "loquace", "chiacchierone", "pettegolo" } },
    
};


/* - function - */
void resword(char *word_searched){
    int i,j;
    int struct_lenght = sizeof(dictionary_words) / sizeof(dictionary_words[0]);
    
    for (i = 0; i < struct_lenght; i++) {
        
        if (strcmp(word_searched, dictionary_words[i].name) == 0) {
            
            printf("\nIl significato della parola cercata è: \n%s\n",dictionary_words[i].meaning);
            printf("\nIl contrario della parola cercata è: \n\n");
            
            for (j=0; j< 5 && strlen(dictionary_words[i].contrary[j]) > 0; j++) {
                printf("%d. %s\n", j+1, dictionary_words[i].contrary[j]);
            }
            
            printf("\n");
        }
    }
}

void opphrase(char *phrase){
    int i = 0, k, j;
    int struct_lenght = sizeof(dictionary_words) / sizeof(dictionary_words[0]);
    char *token;
    char *words[200];
    char separators[] = {' ','\0','\t','\n'};
    
    token = strtok(phrase, separators);
    
    printf("<------------------------------------------------->\n\n");
    
    while (token != NULL) {
        words[i++] = strdup(token);
        token = strtok(NULL," \n");
    }
    
    printf("La tua frase al contrario e':\n");
    for (k = 0; k < i; k++) {
        for (j = 0; j < struct_lenght; j++) {
            if (strcmp(words[k], dictionary_words[j].name) == 0) {
                strcpy(words[k], dictionary_words[j].contrary[0]);
            }
        }
        printf("%s ", words[k]);
    }
    
    printf("\n");
}
