import { DateTime } from "luxon"
import '../scss/styles.scss'
import * as bootstrap from 'bootstrap'

setInterval(() => {
    hh.textContent = DateTime
    .local()
    .setLocale('ru')
    .toFormat('dd.LL.y HH:mm:ss')
}, 1000);
