1 .כותרת:
	Bloxorz

2 .פרטי הסטודנט: שם מלא כפי שהוא מופיע ברשימות המכללה, ת"ז:
	אחמד עליאן, 212159933

3 .הסבר כללי של התרגיל:
	הפרויקט הזה זהה למשחק Bloxorz שמוצאים באינטרנט אבל בצורה דו-מימדית כך שהמטרה להזיז את הצורה שמשתנה כל הזמן בין ריבוע ומלבן על האריחים ולהגיע למקום מסוים בלי ליפול בחורים.
 
4 .תיכון )design :)הסבר קצר מהם האובייקטים השונים בתוכנית, מה התפקיד של כל אחד
מהם וחלוקת האחריות ביניהם ואיך מתבצעת האינטראקציה בין האובייקטים השונים:
	האובייקטים במשחק הזה הם הדמיות שזזות ולא זזות. כך שלכל אובייקט יש לו את התכונות שלו כשהו מתנגש עם השחקן.

5 .רשימה של הקבצים שיצרנו, עם הסבר קצר )לרוב לא יותר משורה או שתיים( לגבי תפקיד
הקובץ:
main.cpp הקובץ הראשי
Conroller.cpp הקובץ שמתנהלת בו המשחק
Conroller.h הקובץ שהגדרנו בו את הפונקציות והאובייקטים של הקובץ הראשי
Character.h הקובץ שהגדרנו בו התכונות המשותפות לדמויות
Hole.cpp  הקובץ שמימשנו בו את התכונות וההתנגשות עם החור
Hole.h הקובץ שהגדרנו בו התכונות של החור
Information.cpp הקובץ שמימשנו בו את המידע והדפסנו אותו למסך
Information.h הקובץ שהגדרנו בו התכונות של המידע
Level.cpp הקובץ שמימשנו בו את קריאת השלבים ומהקובץ
Level.h הקובץ שהגדרנו בו התכונות של השלבים
Menu.cpp הקובץ שמימשנו בו את התפריט והדפסנו אותה
Menu.h הקובץ שהגדרנו בו התכונות של התפריט
Player.cpp הקובץ שמימשנו בו את השחקן והתזוזה שלו
Player.h הקובץ שהגדרנו בו התכונות של השחקן
SpecialTiles.cpp הקובץ שמימשנו בו את האריחים המיוחדים
SpecialTiles.h הקובץ שהגדרנו בו את התכונות של האריחים המיוחדים
StaticChar.h הקובץ שיורשות ממנו הדמויות הללא זזות.
Tiles.cpp  הקובץ שמימשנו בו את האריחים
Tiles.h הקובץ שהגדרנו בו את התכונות של האריחים
Win.cpp הקובץ שמימשנו בו את אריח הניצחון
Win.h הקובץ שהגדרנו בו את התכונות של אריח הניצחון

6 .מבני נתונים עיקריים ותפקידיהם:
	vector כדי לשמור המידע.
	ספרית SFML
	unique_ptr

7 .אלגוריתמים הראויים לציון:
	לכל צורה של השחקן יש את התכונות שלה למשל אי אפשר לנצח אם זה לא היה ריבוע וגם אם חצי של המלבן נגע בחורים גם מפסידים.
8 .באגים ידועים:

9 .הערות אחרות:
ביצירת השלבים כותבים קודם את: שורות עמודות, ואם זה השלב הראשון אני כותבים גם מספר השלבים שאנו הולכים לעשות.
ואחר כך בונים את המשחק: '*' זה השחקן, '=' זה אריח רגיל, '+' זה אריח מיוחד, 'x' זה מקום הניצחון,  ' ' זה החור.
וממולץ שגודל השלב לא יעלה על: 10 שורות, ו- 15 עמודות.  