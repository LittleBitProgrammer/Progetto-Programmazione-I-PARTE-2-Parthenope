//
//  dictionarylib.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                /* - Scopo della libreria - */
                                                           /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                               -----------------------------
                                                       |---->  |       dictionarylib.c     |  <----|
                                                               -----------------------------
 
 La libreria in questione nasce con lo scopo di semplificare le operazioni che il dizionario virtuale deve eseguire durante il suo normale utilizzo.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


                                                            /* - Inclusione header file - */
                                                        /*-----------------------------------*/
#include "dictionarylib.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Inizializzo un array bidimensionale del tipo wordstruct (definito in dictionarylib.h) utile per rappresentare il concetto di "parola di un dizionario" nel contesto del
 software in questione e per applicare su di essi diverse operazioni definite dalle funzioni/procedure presenti nella libreria.
 
 Ho deciso di utilizzare un array bidimensionale piuttosto che un monodimensionale per ottimizzare la ricerca e non scorrere tutto l'array ogni volta che questa operazione
 viene eseguita.
 
 Per semplificare la lettura del codice della libreria di seguito le variabili che definiscono una singola struttura wordstruct :
 
 {
 - parola [lunghezza massima parola]
 - significato parola [lunghezza massima del significato]
 - array di contrari [massimo numero di contrari][massima lunghezza di un contrario]
 }
 
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

static wordstruct dictionary_words[NUMBERS_OF_LETTERS][MAX_WORD_FOR_LETTER] = {
    
    
    /* Lettera A: indice  - 1 - */
    {
        { "abbassare", "calare, far scendere, spostare verso il basso", { "alzare", "far salire", "innalzare" } },
        { "abbellire", "adornare, ornare, rendere più bello, decorare, arricchire, impreziosire, guarnire, ingentilire", { "imbruttire", "deturpare","rovinare" } },
        { "abbastanza", "sufficientemente, quanto basta, a sufficienza, bastantemnte", { "troppo poco", "insufficientemente", "scarsamente" } },
        { "abbandonare", "lasciare, lasciare da parte", { "cessare", "lasciar perdere", "rinunciare", "dimettersi", "abdicare" } },
        { "abbinare", "unire, congiungere, accostare, riunire", { "separare", "dividere" } }
    },
    
    
    /* Lettera B: indice  - 2 - */
    {
        { "baccano", "chiasso, fracasso, frastuono", { "silenzio", "calma", "tranquillità"} },
        { "banale", "privo di originalità, distinzione, importanza", { "elegante", "affascinante","straordinario", "particolare", "insolito" } },
        { "barbaro", "appartenente a un mondo che è lontano dal nostro modo di vivere e di pensare", {"mite", "generoso", "cortese"} },
        { "barboso", "una persona considerata pesante e monotona", {"divertente", "piacevole", "simpatico", "allegro", "interessante"} },
        { "basico", "qualcosa ritenuto fondamentale, di base", {"accessorio","avanzato", "superiore"} }
    },
    
    
    /* Lettera C: indice  - 3 - */
    {
        { "cadaverico", "pallidismo a causa di un cadavere o perdita notevole di sangue", { "colorito", "roseo", "rubicondo", "fiorente"} },
        { "cafone", "una persona dai modi villani", { "gentlemen", "gentiluomo", "signore", "persona fine" } },
        { "cagionevole", "di costituzione molto debole, predispost ad ammalarsi", {"sano", "robusto", "florido", "resistente"} },
        { "calmare", "ridurre alla calma, placare", {"eccitare", "irritare", "innervosire", "stimolare", "fomentare"} },
        { "cancellare", "coprire una scrittura in modo da renderla illeggibile", {"conservare", "tenere", "salvare"} }
    },
    
    
    /* Lettera D: indice  - 4 - */
    {
        { "debito", "Imposto da leggi o consuetudini o richiesto dalle circostanze", { "credito", "attivo", "libero", "volontario"} },
        { "debole", "scarso o privo di forza fisica", { "forte", "robusto","vigoroso","energico" } },
        { "decelerare", "rallentare,diminuire la velocità, andare più piano", {"accellerare"} },
        { "decentrato", "periferico,non centrato", {"centrale", "centralizzato", "accentrato", "centralistico" } },
        { "deciso", "agisce con prontezza, energia e sicurezza", {"indeciso", "incerto", "dubbioso", "odscillante", "titubante" } }
        
    },
    
    
    /* Lettera E: indice  - 5 - */
    {
        { "eccelso", "fuori dal comune, sommo, sublime, eminente", { "infimo", "inferiore", "pessimo", "di basso livello" } },
        { "eccesso", "superamento del limite consentito o tollerato", { "moderazione", "misura","equilibrio", "rispetto" } },
        { "eccezionale", "qualcosa di straordinario o unico", {"usuale", "solito", "quotidiano", "comune", "regolare"} },
        { "economico", "poco costoso, abuon mercato spesso associato a qualcosa di scadente", {"costoso", "caro", "dispendioso", "lussuoso" } },
        { "educato", "che si comporta con civiltà e cortesia", {"maleducato","incivile", "screanzato", "villano", "cafone"} }
    },
    
    
    /* Lettera F: indice  - 6 - */
    {
        { "facile", "che non chiede alcuna dote o applicazione particolare", { "difficile", "arduo", "difficoltoso", "complicato", "complesso"} },
        { "facoltativo", "non obbligatorio", { "obbligatorio", "necessario", "forzato", "inevitabile", "indispensabile" } },
        { "falso", "contrario o non corrispondente al vero", {"vero", "genuino", "autentico"} },
        { "famoso", "universalmente noto perl'eccezionalità degli aspetti positivi o negativi che presenta", {"sconosciuto", "ignoto", "oscuro", "anonimo", "dimenticato"} },
        { "fantasioso", "Dotato di fervida immaginazione", {"realista", "reale", "concreto"} }
    },
    
    
    /* Lettera G: indice  - 7 - */
    {
        { "galantuomo", "persona onesta per bene, gentiluomo", { "malfattore", "furfante", "deliquente", "disonesto", "canaglia"} },
        { "geloso", "tormentato dalla gelosia", { "indifferente", "fiducioso", "sicuro", "certo", "sereno" } },
        { "generico", "che non si fonda su particolari noti o concreti", {"detttagliato", "particolare", "unico", "specializzato", "personale"} },
        { "genio", "disposizione naturale spiccata, attidudine o talento", {"stupido", "sciocco", "nullità", "zero" } },
        { "gigante", "uomo fornito di talento eccezionale, che domini incontrastato in un dato campo o epoca", {"uomo comune","piccolo", "minuscolo"} }
    },
    
    
    /* Lettera H: indice  - 8 - */
    {
        { "handicap", "penalizzazione, svantaggio", { "vantaggio", "facilitazione", "aiuto", "agevolazione"} },
        { "hardware", "materiale elettronico come elaboratori, calcolatori, unità fisiche", { "software" } }
    },
    
    
    /* Lettera I: indice  - 9 - */
    {
        { "ibrido", "individuo animale o vegetale proveniente da un incrocio di genitori appartenenti a razze diverse", { "puro", "di razza", "omogeneo"} },
        { "igienico", "rispondente a determinate esigenze e prescrizioni dell'igiene", { "antigienico", "sporco", "infetto", "malato", "nocivo" } },
        { "ignoto", "non cnosciuto ne identificato o identificabile", { "famoso", "noto", "celebre", "conosciuto", "popolare" } },
        { "illeggibile", "di difficile o impossibile decifrazione, indecifrabile", {"leggibile", "comprensibile", "decifrabile" } },
        { "illogico", "qualcosa di irragionevole o assurdo", { "logico", "ragionevole", "sensato", "ragionevole" } }
    },
    
    
    /* Lettera J: indice  - 10 - */
    {
        { "junior", "minore o persona giovane", { "senior", "anziano", "maggiore"} }
    },
    
    
    /* Lettera K: indice  - 11 - */
    {
        { "killer", "assasino, sicario che uccide a pagamento e non", { "difensore", "tutore", "protettore", "salvatore"} }
    },
    
    
    /* Lettera L: indice  - 12 - */
    {
        { "laborioso", "che presenta notevoli difficoltà, superabili soltanto con sforzo e assidua applicazione", { "facile", "semplice", "rapido"} },
        { "lagnoso", "chi è solito lamentarsi di tutto", { "contento", "soddisfatto","appagato", "compiaciuto" } },
        { "lascivo", "sensuale o lussurioso", {"pudico", "verecondo", "morigerato","costumato", "casto"} },
        { "leale", "persona fedele, devota e sincera", {"infedele", "ingannevole", "falso", "insicero", "traditore"} },
        { "legale", "conforme alla legge", {"illegale", "illecito", "proibito", "vietato" } }
    },
    
    
    /* Lettera M: indice  - 13 - */
    {
        { "macchinoso", "qualcosa di complicato o complesso", { "semplice", "chiaro", "agevole", "lineare"} },
        { "macchiavellico", "persona opportunista,astuta,furba", { "leale", "corretto", "onesto", "chiaro", "franco" } },
        { "maestoso", "qualcosa di solenne o superbo", {"modesto", "umile", "semplice", "dimesso"} },
        { "maggiore", "più grande in senso proprio", {"minore", "piccolo", "inferiore", "secondario", "meno importante"} },
        { "maggiorenne", "persona che ha raggiunto l'eta' maggiore", { "minorenne", "minore", "piccolo"} }
    },
    
    
     /* Lettera N: indice  - 14 - */
    {
        { "nascosto", "qualcosa di occultato, segreto", { "evidente", "aperto", "scoperto", "chiaro", "esplicito"} },
        { "nauseato", "persona disgustata, stomacata", { "desideroso", "voglioso","ingordo", "appetente", "avido" } },
        { "nebbioso", "pieno o coperto di nebbia", {"chiaro", "preciso", "evidente", "lineare", "nitido" } },
        { "necessario", "qualcosa di importantissimo, insdispensabile", {"superfluo", "inutile", "futile", "vano", "accessorio"} },
        { "negare", "smentire, dire di no", { "affermare", "approvare", "accordare" } }
    },
    
    
    /* Lettera O: indice  - 15 - */
    {
        { "obbligatorio", "previsto e imposto per legge o da altre disposizioni normative", { "facoltativo", "libero", "opzionale"} },
        { "obeso", "persona affetta da obesità", { "snello", "secco", "gracile", "magro", "esile" } },
        { "occasionale", "incidentale, imprevisto, inatteso", { "voluto", "cercato", "provocato" } },
        { "occupato", "persona assorbita dai doveri che limitano interruzioni o distrazioni", {"libero", "indipendente", "sgombro", "disoccupato" } },
        { "odioso", "persona detestabile, ripugnante", {"amabile","caro", "simpatico", "gradito"} }
    },
    
    
    /* Lettera P: indice  - 16 - */
    {
        { "pacifico", "persona calma e pacata", { "bellicoso", "violento", "guerresco", "battagliero", "attaccabrighe"} },
        { "paesano", "del paese,del luogo,nostrano", { "forestiero", "straniero" } },
        { "paladino", "cavaliere, guerriero, compione o eroe", { "nemico", "avversario", "oppositore" } },
        { "palese", "qualcosa di evidente e visibile", {"nascosto", "occultato", "celato", "segreto", "oscuro"} },
        { "pallido", "sbiancato nel colorito", { "colorito", "rubizzo", "sano", "sgargiante" } }
    },
    
    
    /* Lettera Q: indice  - 17 - */
    {
        { "qualificabile", "riconducibile a caratteristiche definite", { "inqualificabile", "indefinibile" } },
        { "qualunquista", "seguace del movimento politico del qualunquismo", { "attivista", "impegnato" } }
    },
    
    
    /* Lettera R: indice  - 18 - */
    {
        { "rabbioso", "persona adirata e arrabbiata", { "calmo", "sereno", "pacato", "tranquillo", "quieto"} },
        { "raccomandabile", "persona o servizio consigliabile e affidabile", { "sconsigliabile", "poco raccomandabile", "inaffidabile" } },
        { "radicale", "drastico, risolutivo, definitivo", {"superficiale", "epidermico", "leggero", "blando", "conservatore" } },
        { "radioso", "esaltato da una prorompente e diffusa luminosità", {"nebbioso", "offuscato", "coperto", "opaco", "oscuro"} },
        { "raffinatezza", "distinzione per eleganza e gusto", { "volagarità", "rozzezza", "grossolanità", "sciatteria", "maleducazione" } }
    },
    
    
    /* Lettera S: indice  - 19 - */
    {
        { "sabotatore", "guastatore, persona che ostacola e disturba", { "collaboratore", "sostenitore", "fautore"} },
        { "saccente", "che ostenta in modo irritante un'erudizione o una cultura piu' presunta che reale", { "modesto", "umile","riservato", "semplice", "senza pretese" } },
        { "sacro", "religioso,culturale,liturgico", { "profano", "demoniaco", "diabolico", "maledetto"} },
        { "sadico", "persona crudele, atroce e perversa", { "masochista", "sensibile", "delicato", "angelo", "santo"} },
        { "saggio", "che nell'agire e nel parlare dimostra prudenza", {"stolto", "stupido", "imprudente", "sprovveduto", "avventato"} }
    },
    
    
    /* Lettera T: indice  - 20 - */
    {
        { "taccagno", "persona avara e spilorcia", { "generoso", "prodigo", "largo", "splendido", "mecenate"} },
        { "taciturno", "persona silenziosa", { "loquace", "rumoroso", "chiacchierone", "espansivo", "estroverso" } },
        { "talento", "capacita', bravura", { "incapacita'", "inettitudine", "indifferenza", "indisposizione", "inetto" } },
        { "tecnico", "persona tecnologica", {"culturale", "umanistico", "inesperto" } },
        { "temibile", "pericoloso o inquietante", { "innocuo", "provvidenziale", "benfico" } }
    },
    
    
    /* Lettera U: indice  - 21 - */
    {
        { "ubbidiente", "che esegue prontamente gli ordini ricevuti", { "disubbidiente", "indisciplinato", "ribelle", "inadempiente", "insofferente"} },
        { "ubriaco", "persona soggetta agli effetti dell'alcol", { "sobrio", "astemio", "lucido" } },
        { "ufficiale", "di documento o notizia proveniente dall'autorita' competente", { "ufficioso", "confidenziale", "privato", "incerto", "approssimato" } },
        { "uggioso", "tempo grigio e nuvoloso", { "soleggiato", "bello", "sereno" } },
        { "uguale", "identico o indistinguibile", { "diverso", "differente", "disuguale" } }
    },
    
    
    /* Lettera V: indice  - 22 - */
    {
        { "vago", "cqualcosa di impreciso o indefinito", { "preciso", "definito", "nitido", "chiaro", "netto" } },
        { "validità", "qualcosache ha valore", { "invalidita'", "nullita'", "inefficacia" } },
        { "vandalico", "persona distruttiva e devastatrice", { "costruttivo", "protettivo", "conservativo", "civile", "pacifico" } },
        { "vanitoso", "che fa di tutto per mettere in mostra le proprie qualita' fisiche", {"modesto", "umile", "semplice", "dimesso", "serio"} },
        { "variopinto", "policromo, multicolore", { "monocolore", "a tinta unita", "monocromatico", "uniforme" } }
    },
   
    
    /* Lettera W: indice  - 23 - */
    {
       { "watusso", "gigante, granatiere", { "nano" } }
    },
    
    
    /* Lettera X: indice  - 24 - */
    {
       { "xenofobo", "razzista, sciovinista", { "esterofilo", "tollerante" } }
    },
    
    
    /* Lettera Y: indice  - 25 - */
    {
       { "yankee", "unionista, nordamericano", { "confederato", "sudista" } }
    },
    
    
    /* Lettera Z: indice  - 26 - */
    {
       { "zelo", "premura, diligenza o attenzione", { "negligenza", "svogliatezza", "apatia", "indolenza", "pigrizia" } },
       { "zitto", "silenzioso o taciturno", { "loquace", "chiacchierone", "pettegolo" } }
    }
    
};


                                                                  /* - Funzioni - */
                                                        /*-----------------------------------*/



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        resword
 
 * input:       - array monodimensionale di caratteri (stringa)
 
 * output:      ricerca parola corrispondente a quella cercata e ne stampa il significato e i suoi contrari
 
 * descrizione: procedura che accetta in input una stringa e cerca quella corrispondente nell'array bidimensionale di wordstruct mostrandone significato e lista dei
                contrari, se non è presente nell'array allora non mostra le precedenti informazioni
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void resword(char *word_searched){
    //indici dei cicli fot
    int i,j;
    //indice di riga nell'array bidimensionale di wordstruct
    int index_f_letter = returnLetIndex(word_searched[0]);
    
    //gli elementi per ogni riga al massimo possono essere 5
    for (i = 0; i < MAX_WORD_FOR_LETTER; i++) {
        
        //lo strcmp compara due stringhe e restituisce 0 se queste sono uguali
        //quindi se lo strcmp tra la parola cercata e la variabile name della struct alla riga "index_f_letter" e al momento iesimo è uguale a 0, allora le due parole
        //sono uguali
        if (strcmp(word_searched, dictionary_words[index_f_letter][i].name) == 0) {
            
            //quindi siamo nel caso in cui le due parole sono uguali
            //stampa prima il suo significato
            printf("\nIl significato della parola cercata è: \n%s\n",dictionary_words[index_f_letter][i].meaning);
            printf("\nIl contrario della parola cercata è: \n\n");
            
            //utilizza un secondo ciclo for per stampare la lista dei suoi contrari
            //per evitare scorrere l'array più del dovuto, il for scorrerà fino a quando la lunghezza del contrario sarà maggiore di 0, altrimenti quel campo è vuoto
            //ed il ciclo for smette di iterare
            for (j=0; j< 5 && strlen(dictionary_words[index_f_letter][i].contrary[j]) > 0; j++) {
                printf("%d. %s\n", j+1, dictionary_words[index_f_letter][i].contrary[j]);
            }
            
            printf("\n");
        }
    }
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        opphrase
 
 * input:       - array monodimensionale di caratteri (stringa)
 
 * output:      ricerca il contrario della frase data in input
 
 * descrizione: procedura che accetta in input una stringa e stampa a video il suo esatto contrario (i contrari fanno riferimento alle parole presenti nell'array
                bidimensionale di wordstruct)
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void opphrase(char *phrase){
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     indici:
     
     - i    -> indice while
     - k,j  -> indici di for
     
     -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    int i = 0, k, j;
    
    //indice di riga nell'array bidimensionale di wordstruct non inizializzato
    int index_f_letter;
    
    //variabile necesaria dividere la frase in parole
    char *token;
    
    //array di stringhe per memorizzare la lista delle parole spacchettate dalla frase attraverso la funzione strtok
    char *words[200];
    
    //array di separatori utili a capire secondo quale carattere la frase deve essere divisa in parole
    char separators[] = {' ','\0','\t','\n'};
    
    //strtok provvede a dividere una frase in parole dati in input una frase e dei separatori
    token = strtok(phrase, separators);
    
    printf("<------------------------------------------------->\n\n");
    
    //fino a quando token non è nullo continua a duplicare con stdrup token nell'array words al momento iesimo e incrementa i
    while (token != NULL) {
        words[i++] = strdup(token);
        token = strtok(NULL," \n");
    }
    
    printf("La tua frase al contrario e':\n");
    
    //stampa della frase al contrario
    for (k = 0; k < i; k++) {
        for (j = 0; j < MAX_WORD_FOR_LETTER; j++) {
            
            //indice di riga nell'array bidimensionale di wordstruct inizializzato
            index_f_letter = returnLetIndex(words[k][0]);
            
            //lo strcmp compara due stringhe e restituisce 0 se queste sono uguali
            //quindi se lo strcmp tra la parola al momento k e la variabile name della struct alla riga "index_f_letter" e al momento jesimo è uguale a 0,
            //allora le due parole sono uguali
            if (strcmp(words[k], dictionary_words[index_f_letter][j].name) == 0) {
                
                //nel caso siano uguali copia in words al momento k il suo contrario
                strcpy(words[k], dictionary_words[index_f_letter][j].contrary[0]);
            }
        }
        //quindi per ogni words al momento k stampa la parola con uno spazio
        printf("%s ", words[k]);
    }
    
    printf("\n");
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        returnLetIndex
 
 * input:       - un carattere
 
 * output:      ritorna l'indice alfabetico della lettera
 
 * descrizione: funzione che dato in input un carattere restituisce l'indice alfabetico di quest'ultimo, la funzione viene spesso utilizzata per assegnare ad una variabile
                l'indice di riga della parola cercata.
 
 * versione:    1.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
alphabet_index returnLetIndex(char letter){
    
    switch (letter) {
            
        case 'a':
            return a;
            break;
            
        case 'b':
            return b;
            break;
            
        case 'c':
            return c;
            break;
            
        case 'd':
            return d;
            break;
        
        case 'e':
            return e;
            break;
            
        case 'f':
            return f;
            break;
            
        case 'g':
            return g;
            break;
            
        case 'h':
            return h;
            break;
            
        case 'i':
            return i;
            break;
            
        case 'j':
            return j;
            break;
            
        case 'k':
            return k;
            break;
            
        case 'l':
            return l;
            break;
            
        case 'm':
            return m;
            break;
            
        case 'n':
            return n;
            break;
            
        case 'o':
            return o;
            break;
            
        case 'p':
            return p;
            break;
            
        case 'q':
            return q;
            break;
            
        case 'r':
            return r;
            break;
            
        case 's':
            return s;
            break;
            
        case 't':
            return t;
            break;
            
        case 'u':
            return u;
            break;
            
        case 'v':
            return v;
            break;
            
        case 'w':
            return w;
            break;
            
        case 'x':
            return x;
            break;
            
        case 'y':
            return y;
            break;
            
        case 'z':
            return z;
            break;
            
        default:
            return a;
            break;
    }
}
