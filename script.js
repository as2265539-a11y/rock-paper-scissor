let userScore = 0;
let computerScore = 0;
let gameActive = true;

const choices = ["Stone", "Paper", "Scissors"];

const userScoreElement = document.getElementById("userScore");
const computerScoreElement = document.getElementById("computerScore");
const userChoiceElement = document.getElementById("userChoice");
const computerChoiceElement = document.getElementById("computerChoice");
const resultElement = document.getElementById("result");
const exitMessageElement = document.getElementById("exitMessage");
const choiceButtons = document.querySelectorAll(".choice-btn");

function getComputerChoice() {
    const randomIndex = Math.floor(Math.random() * choices.length);
    return choices[randomIndex];
}

function determineWinner(userChoice, computerChoice) {
    if (userChoice === computerChoice) return "Draw!";

    if (
        (userChoice === "Stone" && computerChoice === "Scissors") ||
        (userChoice === "Paper" && computerChoice === "Stone") ||
        (userChoice === "Scissors" && computerChoice === "Paper")
    ) {
        userScore++;
        return "User wins!";
    }

    computerScore++;
    return "Computer wins!";
}

function playRound(userChoice) {
    if (!gameActive) return;

    const computerChoice = getComputerChoice();
    const result = determineWinner(userChoice, computerChoice);

    userChoiceElement.textContent = userChoice;
    computerChoiceElement.textContent = computerChoice;
    resultElement.textContent = result;
    userScoreElement.textContent = userScore;
    computerScoreElement.textContent = computerScore;
}

function resetGame() {
    userScore = 0;
    computerScore = 0;
    gameActive = true;

    userScoreElement.textContent = "0";
    computerScoreElement.textContent = "0";
    userChoiceElement.textContent = "-";
    computerChoiceElement.textContent = "-";
    resultElement.textContent = "Choose Stone, Paper, or Scissors to start.";
    exitMessageElement.textContent = "";

    choiceButtons.forEach(button => button.disabled = false);
}

function exitGame() {
    gameActive = false;
    exitMessageElement.textContent = "Game exited. Click Reset Score to play again.";
    choiceButtons.forEach(button => button.disabled = true);
}

choiceButtons.forEach(button => {
    button.addEventListener("click", () => playRound(button.dataset.choice));
});

document.getElementById("resetBtn").addEventListener("click", resetGame);
document.getElementById("exitBtn").addEventListener("click", exitGame);
