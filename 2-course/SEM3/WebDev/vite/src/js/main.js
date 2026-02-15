import { DateTime } from "luxon";
import '../scss/styles-full.scss';
import 'bootstrap';

function updateTime() {
    const timeElement = document.getElementById("time-display");
    if (timeElement) {
        timeElement.textContent = DateTime
            .local()
            .setLocale('ru')
            .toFormat('dd.LL.y HH:mm:ss');
    }
}

setInterval(updateTime, 1000);

document.addEventListener('DOMContentLoaded', updateTime);