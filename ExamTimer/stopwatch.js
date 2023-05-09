class Stopwatch{
    constructor(){
        this.stopwatchString = "";
        this.flagArray = [];
        this.pause = true;
        this.minute1 = 0;
        this.minute2 = 0;
        this.second1 = 0;
        this.second2 = 0;
        this.milisecond1 = 0;
        this.milisecond2 = 0;
        this.stopwatchGeneral = document.querySelector(".stopwatchGeneral");
        this.stopwatchFlag = document.querySelector(".flagDiv");
        
    }

    init(){
        this.stopwatchString = this.stopwatchTick();
        this.draw(this.stopwatchString);
    }
    

    draw(str){
        this.stopwatchGeneral.innerHTML = str;
    }
    
    stopwatchTick(){
        var stopwatchStr = "" + this.minute1 + this.minute2 + " : " + this.second1 + this.second2 + " : " + this.milisecond1 + this.milisecond2;
        if(this.pause == false){

        this.milisecond2++;
        if (this.milisecond2 > 9) {
            this.milisecond1++;
            if (this.milisecond1 > 5) {
                this.second2++;
                if (this.second2 > 9) {
                    this.second1++;
                    if (this.second1 > 5) {
                        this.minute2++;
                        if (this.minute2 > 9) {
                            this.minute1++;
                            if (this.minute1 == 5) {

                                this.Pause();

                            }
                            this.minute2 = 0;
                        }
                        this.second1 = 0;
                    }
                    this.second2 = 0;
                }
                this.milisecond1 = 0;
            }
            this.milisecond2 = 0;
        }
    }
        return stopwatchStr;
    }

    Pause = () => {
        this.pause = true;
    }

    Continue = () => {
        this.pause = false;
    }

    Reset = () => {
        this.pause = true;
        this.minute1 = 0;
        this.minute2 = 0;
        this.second1 = 0;
        this.second2 = 0;
        this.milisecond1 = 0;
        this.milisecond2 = 0;
        this.ClearFlags();
    }

    Flag = () => {
        var newDiv = this.CreateDiv();
        newDiv.innerHTML = this.stopwatchString;
        newDiv.insertAdjacentHTML("beforeend",' <i class="fa-solid fa-flag fa-xs"></i>');
    };

    CreateDiv(){
        const newDiv = document.createElement("div");
        this.stopwatchFlag.appendChild(newDiv);
        newDiv.style = "margin-left: 10px; margin-top: 2px;"
        this.flagArray.push(newDiv);
        this.ClearFlagsLast();
        return newDiv;
    }

    ClearFlags(){
        this.flagArray.forEach(element => {
            element.remove();
        });
    }

    ClearFlagsLast(){
        if (this.flagArray.length > 5) {
            this.flagArray.shift().remove();
        }
    }
}