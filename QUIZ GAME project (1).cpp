#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

struct Question {
    char text[100];
    char options[4][50];
    int correctOption;
};

struct Information {
    char name[50];
    char rollno[20];
};

void clearScreen() {
    system("cls");  
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayQuestions(struct Question questions[], int currentQuestion) {
    int i;
    setConsoleColor(15);  
    printf("%s\n", questions[currentQuestion].text);
    for (i = 0; i < 4; ++i) {
        printf("%d. %s\n", i + 1, questions[currentQuestion].options[i]);
    }
    setConsoleColor(7); 
}

int getUserChoice() {
    int choice;
    printf("Enter your choice (1-4) or 0 to skip: ");
    while (1) {
        if (scanf("%d", &choice) == 1 && choice >= 0 && choice <= 4) {
            break;
        } else {
            printf("Invalid input. Please enter a number between 0 and 4: ");
            while (getchar() != '\n');
        }
    }
    return choice;
}

void skipQuestion(struct Question skippedQuestions[], int *skippedCount, struct Question currentQuestion) {
    skippedQuestions[*skippedCount] = currentQuestion;
    (*skippedCount)++;
    printf("Question skipped!\n");
}

void displayResult(int score, int totalQuestions) {
    printf("Your score: %d/%d\n", score, totalQuestions);
}

void shuffleQuestions(struct Question questions[], int totalQuestions) {
    int i;
    for (i = totalQuestions - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        struct Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int attemptQuestions(struct Question questions[], int totalQuestions, int totalTime, int *score) {
    time_t startTime = time(NULL);
    int i;
    int skippedCount = 0;
    struct Question skippedQuestions[totalQuestions];

    for (i = 0; i < totalQuestions; ++i) {
        if (difftime(time(NULL), startTime) >= totalTime) {
            printf("Time's up! Quiz terminated.\n");
            break;
        }

        clearScreen();
        displayQuestions(questions, i);
        int userChoice = getUserChoice();

        if (userChoice == 0) {
            skipQuestion(skippedQuestions, &skippedCount, questions[i]);
            continue;
        }

        if (userChoice == questions[i].correctOption) {
            setConsoleColor(10);  
            printf("Correct!\n");
            (*score)++;
        } else {
            setConsoleColor(12);  
            printf("Incorrect!\n");
            (*score)--;
        }
        setConsoleColor(7);  

        Sleep(1000);  
    }

    clearScreen();
    printf("\nSkipped Questions:\n");
    for (i = 0; i < skippedCount; ++i) {
        displayQuestions(skippedQuestions, i);
        int userChoice = getUserChoice();
        if (difftime(time(NULL), startTime) >= totalTime) {
            printf("Time's up! Quiz terminated.\n");
            break;
        }

        if (userChoice == 0) {
            printf("Question skipped again!\n");
            i--;
        } else if (userChoice == skippedQuestions[i].correctOption) {
            printf("Correct!\n");
            (*score)++;
        } else {
            printf("Incorrect!\n");
            (*score)--;
        }
    }

    displayResult(*score, totalQuestions);
    return *score;
}

int main() {
    char userchoice;
    struct Information info;

    printf("Do you want to start the test (Y/N): ");
    scanf(" %c", &userchoice);
    
    if (userchoice == 'Y' || userchoice == 'y') {
        FILE *fptr;
        fptr = fopen("Results.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file!");
            return 1;
        }

        label:
        clearScreen();
        printf("\nWELCOME TO THE TEST\n");
        setConsoleColor(11);  
        printf("INSTRUCTIONS:\n");
        printf("1. Arrive at the examination venue at least 15 minutes before the start of the examination/35 minutes before a digital examination.\n");
        printf("2. The examination starts at the moment the book control begins, and you must therefore be present by 8:20 a.m. for regular written examinations and 8:10 a.m. at digital examinations.\n");
        printf("3. When using a laptop at digital examinations, the laptop has to be set up as soon as possible. If you are taking a law exam, the laptop must be set up before the book control.\n");
        printf("4. The head invigilator will provide information about examination support materials that you are permitted to use during the examination.\n");
        setConsoleColor(7);  

        srand(time(NULL));
        
        printf("\nEnter your name: ");
        scanf("%s", info.name);
        printf("Enter your roll number: ");
        scanf("%s", info.rollno);

       
        struct Question questions[30] = {
            {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 2},
            {"What is the powerhouse of the cell?", {"Nucleus", "Mitochondria", "Ribosome", "Endoplasmic Reticulum"}, 2},
            {"Which of the following cell organelles does not contain DNA?",{"Nucleus","Lysosomes","Chloroplast","Mitochondria"},2},
            {"Which of the following cell organelles is called a suicidal bag?",{"Nucleus","Lysosomes","Chloroplast","Mitochondria"},2},
            {"Which of the following is a single membrane-bound organelle?",{"Vacuole","Golgi Apparatus","Endoplasmic Reticulum","All of the above"},4},
            {"Which of the following is a symptom of AIDS?",{"Fever","Swollen lymph nodes","Tiredness","All of the above"},4},
            {"The first ever instance of AIDS was reported in",{"USA","France","Russia","None of the above"},1},
            {"HIV parasitizes",{"Y-helper cells","T-helper cells","K-helper cells","None of the above"},2},
            {"How many stages of HIV infection exist?",{"3","2","1","No stages"},1},
            {"Phyllotaxy is",{"Folding leaf in thebud","Arrangement of leaves on the stem","Both (1) and (2)","None"},2},
            {"Nodulated roots enrich the plant with",{"Proteins","Fats","Carbohydrates","Food"},1},
            {"Bacteria protect themselves from viruses by fragmenting viral DNA with",{"Ligase","Endonuclease","Exonuclease","Gyrase"},2},
            {"The main function of guard cells is to help with",{"Transpiration","Guttation","Transcription","None of above"},1},
            {"Cell signaling is",{"Intercellular","Intracellular","Both 1 and 2","None"},3},
            {"Which of the following signal molecules is not used for extracellular signaling?",{"Cyclic AMP","Endocrine","Both","None"},1},
            {"What is the capital of France?", {"Berlin", "Paris", "London", "Rome"}, 2},
            {"Which planet is known as the Red Planet?", {"Mars", "Venus", "Jupiter", "Saturn"}, 1},
            {"How many continents are there?", {"5", "6", "7", "8"}, 3},
            {"who is the prime minister of pakistan?",{"Nawaz Sharif","Imran Khan","Altaf Hussain","Anwar-ul-Haq"},4},
            {"how many months are there in a year?",{"12","11","10","13"},1},
            {"Which of the following is not found in France?",{"Eiffel tower","Louvre","Burj-khalifa","Arc-de-triomphe"},3},
            {"What is the capital of China?",{"Beijing","Islamabad","Paris","Tokyo"},1},
            {"Which is larger the Pacific or the Atlantic Ocean?",{"Pacific","Atlantic","Both","None"},1},
            {"In which country would you find Angel Falls, the highest waterfall on earth?",{"Veneuzela","Paris","Italy","None of above"},1},
            {"How many states are there in America?",{"50","60","20","70"},1},
            {"What mountain range would you find in India, China and Nepal (amongst other countries)?",{"Himalaya","K2","Kirthar","None"},1},
            {"Which civilisation was responsible for the pyramids?",{"Ancient Egyptians","Chinese","Koreans","Sapiens"},1},
            {"Babe Ruth is synonymous with which sport?",{"Baseball","Basketball","Tennis","Cricket"},1},
            {"What is the name of the royal singer who turned the rain purple?",{"Prince","King","Chef","Queen"},1},
            {"Kurt Cobain was the frontman for which Grunge band?",{"Nirvana","Cape","Kale","Kros"},1}
        };

        int totalQuestions = sizeof(questions) / sizeof(questions[0]);
        int totalTime = 100;
        int score = 0;

        shuffleQuestions(questions, totalQuestions);
        score = attemptQuestions(questions, totalQuestions, totalTime, &score);
fprintf(fptr, "Name: %s, Roll No: %s, Score: %d/%d, Total Time: %d seconds\n", 
                info.name, info.rollno, score, totalQuestions, totalTime);

        fclose(fptr);
        printf("Results saved to file.\n");

        printf("\nDo you want to retake the test? (Y/N): ");
        scanf(" %c", &userchoice);
        if (userchoice == 'Y' || userchoice == 'y') {
            goto label;
        }
    } else {
        printf("Thank you! Goodbye.\n");
    }

    return 0;
}
