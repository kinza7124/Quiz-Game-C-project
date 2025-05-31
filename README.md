# Quiz Application  

## Introduction  
The Quiz Application is a console-based program developed in **C language**. It allows users to:  
- Take a quiz consisting of multiple-choice questions  
- Track their score  
- Review their performance  
- Shuffle questions for variety  
- Skip questions and return to them later  
- Complete the quiz within a time limit  

## Objectives  
- Create an engaging and interactive quiz experience  
- Implement a time-bound quiz system  
- Allow question skipping and reviewing  
- Store and display quiz results  

## Features  
✔ **Question Display** – Shows multiple-choice questions with four options  
✔ **User Input** – Accepts answer selection or question skipping  
✔ **Score Tracking** – Calculates and updates score based on correct/incorrect answers  
✔ **Shuffling Questions** – Randomizes question order for each attempt  
✔ **Skipped Questions** – Lets users skip and revisit questions later  
✔ **Time Limit** – Enforces a time constraint for the quiz  
✔ **Results Storage** – Saves quiz results to a file for future reference  

## Implementation Details  
Built in **C language**, the application consists of the following components:  

### 1. Structure Definitions  
- **`Question` Structure** – Stores question text, options, and correct answer  
- **`Information` Structure** – Holds user details (name, roll number)  

### 2. Core Functions  
- **`clearScreen()`** – Clears the console screen  
- **`setConsoleColor(int color)`** – Sets console text color for better UI  
- **`displayQuestions()`** – Shows current question and options  
- **`getUserChoice()`** – Captures user input for answering/skipping  
- **`skipQuestion()`** – Adds current question to skipped list  
- **`displayResult()`** – Shows final score and performance  
- **`shuffleQuestions()`** – Randomizes question order  
- **`attemptQuestions()`** – Manages quiz flow, time tracking, and skipped questions  
## User Interaction  
1. **Quiz Start** – User initiates the quiz  
2. **Instructions** – Application displays quiz rules  
3. **User Details** – Prompts for name and roll number  
4. **Quiz Session** – Displays questions, tracks time, and accepts answers  
5. **Results** – Shows score and saves results to a file  estions.
