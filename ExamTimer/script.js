stopwatch1 = new Stopwatch();
const startButton = document.querySelector(".start");
const pauseButton = document.querySelector(".pause");
const resetButton = document.querySelector(".reset");
const flagButton = document.querySelector(".flag");

stopwatch1.init();
setInterval(() => {stopwatch1.init()},10);


startButton.addEventListener("click",stopwatch1.Continue);
pauseButton.addEventListener("click",stopwatch1.Pause);
resetButton.addEventListener("click",stopwatch1.Reset);
flagButton.addEventListener("click",stopwatch1.Flag);



