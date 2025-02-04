Quiz Application
1. Introduction
The Quiz Application is a console-based program developed in C language. It allows users to take a quiz consisting of multiple-choice questions, track their score, and review their performance. The application shuffles the questions, supports skipping questions, and provides a time limit for the quiz.

2. Objectives
To create an engaging and interactive quiz application.
To implement a time-bound quiz system.
To allow users to skip and review questions.
To store and display results.

3. Features
Question Display: Displays multiple-choice questions with four options.
User Input: Allows users to select an option or skip a question.
Score Tracking: Tracks correct and incorrect answers, adjusting the score accordingly.
Shuffling Questions: Randomizes the order of questions for each attempt.
Skipped Questions: Allows users to skip questions and review them later.
Time Limit: Enforces a time limit for the entire quiz.
Results Storage: Saves quiz results to a file.

4. Implementation Details
The Quiz Application is implemented using C language with the following main components:

4.1. Structure Definitions
Question Structure: Holds the question text, options, and the correct option.
Information Structure: Holds the user's name and roll number.

4.2. Core Functions
clearScreen(): Clears the console screen.
setConsoleColor(int color): Sets the console text color.
displayQuestions(): Displays the current question and options.
getUserChoice(): Gets the user's choice for the current question.
skipQuestion(): Adds the current question to the list of skipped questions.
displayResult(): Displays the final score.
shuffleQuestions(): Randomizes the order of questions.
attemptQuestions(): Handles the main quiz logic, including time tracking and skipped questions review.

5. User Interaction
The application begins by prompting the user to start the quiz. It then displays instructions and asks for the user's name and roll number. The quiz proceeds by displaying questions and accepting user input. At the end of the quiz, the results are displayed and saved to a file.
