from re import findall
from datetime import datetime, timedelta

class Submission:
    def __init__(self, time_of_sub, problem, verdict, lang, id):
        self.time_of_sub = time_of_sub
        self.problem = problem
        self.verdict = verdict
        self.lang = lang
        self.id = id

    def get_data(self) -> tuple:
        return (self.id, self.lang, self.verdict, self.problem, self.time_of_sub)

    def __eq__(self, obj) -> bool:
        return self.get_data() == obj.get_data()

    def __ne__(self, __o: object) -> bool:
        return not self.__eq__(__o)

    def __str__(self) -> str:
        return str(self.get_data())

def parse_time(text: str) -> datetime:
    if "AM" in text or "PM" in text:
        date = findall(r'\d+/\d+/\d+', text)[0]
        time = findall(r'\d+:\d+', text)[0]
        time_of_sub = datetime.strptime(date + ' ' + time, '%d/%m/%y %H:%M')
        return time_of_sub + timedelta(hours = 12) if "PM" in text else time_of_sub
    else:
        delta = findall(r'\d+ [a-zA-Z]+ ago', text)[0]
        value = findall(r'\d+', delta)[0]
        now = datetime.now().strftime('%d/%m/%y %H:%M')
        now = datetime.strptime(now, '%d/%m/%y %H:%M')
        if 'sec' in delta:
            delta = timedelta(seconds = int(value))
        elif 'min' in delta:
            delta = timedelta(minutes = int(value))
        elif 'hour' in delta:
            delta = timedelta(hours = int(value))
        time_of_sub = now - delta
        return time_of_sub

def parse_problem(text: str) -> str:
    regex = r'/problems/[a-zA-Z0-9]+'
    return findall(regex, text)[0].split('/')[-1]

def parse_verdict(text: str) -> str:
    verdict = 'NA'
    if 'tick' in text:
        verdict = 'AC'
    elif 'cross' in text:
        verdict = 'WA'
    elif 'clock_error' in text:
        verdict = 'TLE'
    elif 'runtime' in text:
        verdict = 'RE'
    elif 'alert':
        verdict = 'CE'
    return verdict


def parse_lang(text):
    return text.split('</td>')[3].split('>')[-1]

def parse_id(text):
    if 'disabled' in text:
        return 'NA'
    else:
        regex = r'viewsolution/\d+'
        text = findall(regex, text)[0]
        return findall(r'\d+', text)[0]

def parse_submission(text: str) -> Submission:
    time_of_sub = parse_time(text)
    problem = parse_problem(text)
    verdict = parse_verdict(text)
    lang = parse_lang(text)
    id = parse_id(text)
    submission = Submission(time_of_sub, problem, verdict, lang, id)
    return submission