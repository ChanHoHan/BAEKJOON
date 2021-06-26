function solution(progresses, speeds) {
    var answer = [], _time = 0, val;
    
    while (progresses.length != 0)
    {
        _time = parseInt(Math.ceil(((100 - progresses[0]) / speeds[0])));
        val = 1;
        progresses.shift();
        speeds.shift();
        while (progresses.length != 0)
        {
            if (progresses[0] + _time * speeds[0] >= 100)
                {
                    val++;
                    progresses.shift();
                    speeds.shift();
                }
            else
                break;           
        }
        answer.push(val)
    }
    return answer;
}
