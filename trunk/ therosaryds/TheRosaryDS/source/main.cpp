// The RosaryDS v1.3.1.0
// TheRosaryDS.googlecode.com
// WHAT'S NEW:	- Scripture text for the mysteries.
//				- New font for Scripture text.
//				- Formatted 'What is the Rosary' text.
//				- Added version number to credits.
// TODO:		- 
// Copyright 2008 Joseph Socoloski. All Rights Reserved. 
////////////////////////////////////////////////////////
// Includes
#include <PA9.h>    // Include for PA_Lib
#include <n3d.h>	// Include for lib3d
#include <nds.h>	//Include for libnds
#include <fat.h>	// C:\devkitPro\libnds\include
#include <stdio.h>	//Include for string support
#include <iostream>	//Include for string support
#include <fstream>	//Include for string support
using namespace std;//Include for string support
#include "transition.h"
#include "scrollsprites.h"
#include "collision.h"
#include "gfx/all_gfx.h"
#include "gfx/all_gfx.c"
#include "jsds_intro.h"
#include "TheApostlesCreed.h"
#include "step1.h"
#include "step2.h"
#include "step3.h"
#include "step4.h"
#include "step5.h"
#include "step6.h"
#include "step7.h"
#include "step8.h"
#include "step9.h"
#include "step10.h"
#include "step11.h"
#include "step12.h"
#include "step13.h"
#include "step14.h"
#include "step15.h"
#include "step16.h"
#include "step17.h"
#include "step18.h"
#include "step19.h"
#include "GlorybeTotheFather.h"
#include "OurFather.h"
#include "SignoftheCross.h"
#include "click.h"
#include "HailMary.h"
#include "HymnMyMothersPrayer.h"
#include "HymnForAlltheSaints.h"
#include "HymnWhatGrace.h"
#include "TheRosaryIs.h"
#include "TheRosaryIs.h"
bool finished = FALSE;
int leap (int year);
//384 count

std::string txtApostlesC_1 = "The Apostles' Creed: I believe  in God, the Father almighty,    creator of heaven and earth;and in Jesus Christ, His only Son,  our Lord, who was conceived by  the Holy Spirit, born of the    Virgin Mary, suffered under     Pontius Pilate, was crucified,  died, and was buried;He         descended into hell. On the     third day he rose again;He      ";
std::string txtApostlesC_2 = "ascended into heaven, sits at   the right hand  of God, The     Father Almighty, from thence he shall come to judge the quick   and the dead. I believe in the  Holy Spirit, the  Holy Catholic Church, the communion of        saints,the forgiveness of sins, the resurrection of the body,   and the life everlasting. Amen.";
std::string txtOurFather_1 = "The Our Father:Our Father, Who  art in heaven Hallowed be Thy   Name;Thy kingdom come,Thy will  be done,on earth as it is in    heaven.Give us this day our     daily bread,and forgive us our  trespasses,as we forgive those  who trespass against us;and leadus not into temptation,but      deliver us from evil. Amen.";
std::string txtHailMary_1  = "Hail Mary, full of grace.Our    Lord is with thee.Blessed art   thou among women,and blessed    is the fruit of thy womb Jesus. Holy Mary, Mother of God,pray   for us sinners,now and at the   hour of our death.";
std::string txtGloryBe_1   = "Glory be to the Father,and to   the Son, and to the Holy Spirit.As it was in the beginning,is   now, and ever shall be,world    without end.";

std::string txtJoyful1_1	= "It had been revealed to him by  the holy Spirit that he should  not see death before he had seenthe Messiah of the Lord. He camein the Spirit into the temple;  and when the parents brought in the child Jesus to perform the  custom of the law in regard to  him,he took him into his arms   and blessed God, saying:'Now,   Master, you may let your servant";
std::string txtJoyful1_2	= "go in peace, according to your  word, for my eyes have seen yoursalvation, which you prepared insight of all the peoples, a     light for revelation to the     Gentiles, and glory for your    people Israel.'The child's      father and mother were amazed atwhat was said about him;and     Simeon blessed them and said to Mary his mother, 'Behold, this  ";
std::string txtJoyful1_3	= "child is destined for the fall  and rise of many in Israel, and to be a sign that will be       contradicted(and you yourself a sword will pierce) so that the  thoughts of many hearts may be  revealed.' There was also a     prophetess, Anna, the daughter  of Phanuel, of the tribe of     Asher. She was advanced in      years, having lived seven years ";
std::string txtJoyful1_4	= "with her husband after her      marriage, and then as a widow   until she was eighty-four. She  never left the temple, but      worshiped night and day with    fasting and prayer. And coming  forward at that very time, she  gave thanks to God and spoke    about the child to all who were awaiting the redemption of      Jerusalem.";

std::string txtJoyful2_1	= "During those days Mary set out  and traveled to the hill countryin haste to a town of Judah,    where she entered the house of  Zechariah and greeted Elizabeth.When Elizabeth heard Mary's     greeting, the infant leaped in  her womb, and Elizabeth, filled with the holy Spirit, cried out in a loud voice and said, \"Most blessed are you among women, and";
std::string txtJoyful2_2	= "blessed is the fruit of your    womb. And how does this happen  to me, that the mother of my    Lord should come to me? For at  the moment the sound of your    greeting reached my ears, the   infant in my womb leaped for    joy. Blessed are you who        believed that what was spoken toyou by the Lord would be        fulfilled.\" And Mary said: \"My  ";
std::string txtJoyful2_3	= "soul proclaims the greatness of the Lord; my spirit rejoices in God my savior. For he has lookedupon his handmaid's lowliness;  behold, from now on will all    ages call me blessed. The MightyOne has done great things for   me, and holy is his name. His   mercy is from age to age to     those who fear him. He has shownmight with his arm, dispersed   ";
std::string txtJoyful2_4	= "the arrogant of mind and heart. He has thrown down the rulers   from their thrones but lifted upthe lowly. The hungry he has    filled with good things; the    rich he has sent away empty. He has helped Israel his servant,  remembering his mercy, accordingto his promise to our fathers,  to Abraham and to his           descendants forever.\" Mary      ";
std::string txtJoyful2_5	= "remained with her about three   months and then returned to her home. When the time arrived for Elizabeth to have her child she gave birth to a son. Her        neighbors and relatives heard   that the Lord had shown his     great mercy toward her, and theyrejoiced with her.";

std::string txtJoyful3_1	= "In those days a decree went out from Caesar Augustus that the   whole world should be enrolled. This was the first enrollment,  when Quirinius was governor of  Syria. So all went to be        enrolled, each to his own town. And Joseph too went up from     Galilee from the town of        Nazareth to Judea, to the city  of David that is called         ";
std::string txtJoyful3_2	= "Bethlehem, because he was of thehouse and family of David, to beenrolled with Mary, his         betrothed, who was with child.  While they were there, the time came for her to have her child, and she gave birth to her       firstborn son. She wrapped him  in swaddling clothes and laid   him in a manger, because there  was no room for them in the inn.";
std::string txtJoyful3_3	= "Now there were shepherds in thatregion living in the fields and keeping the night watch over    their flock. The angel of the   Lord appeared to them and the   glory of the Lord shone around  them, and they were struck with great fear. The angel said to   them, \"Do not be afraid; for    behold, I proclaim to you good  news of great joy that will be  ";
std::string txtJoyful3_4	= "for all the people. For today inthe city of David a savior has  been born for you who is Messiahand Lord. And this will be a    sign for you: you will find an  infant wrapped in swaddling     clothes and lying in a          manger.\"And suddenly there was amultitude of the heavenly host  with the angel, praising God andsaying: \"Glory to God in the    ";
std::string txtJoyful3_5	= "highest and on earth peace to   those on whom his favor rests.\" When the angels went away from  them to heaven, the shepherds   said to one another, \"Let us go,then, to Bethlehem to see this  thing that has taken place,     which the Lord has made known tous.\" So they went in haste and  found Mary and Joseph, and the  infant lying in the manger. When";
std::string txtJoyful3_6	= "they saw this, they made known  the message that had been told  them about this child. All who  heard it were amazed by what hadbeen told them by the shepherds.And Mary kept all these things, reflecting on them in her heart.Then the shepherds returned,    glorifying and praising God for all they had heard and seen,    just as it had been told to     ";
std::string txtJoyful3_7	= "them.";

std::string txtJoyful4_1	= "When eight days were completed  for his circumcision, he was    named Jesus, the name given him by the angel before he was      conceived in the womb. When the days were completed for their   purification according to the   law of Moses, they took him up  to Jerusalem to present him to  the Lord, just as it is written in the law of the Lord, \"Every  ";
std::string txtJoyful4_2	= "male that opens the womb shall  be consecrated to the Lord,\" andto offer the sacrifice of \"a    pair of turtledoves or two youngpigeons,\" in accordance with thedictate in the law of the Lord. Now there was a man in Jerusalemwhose name was Simeon. This man was righteous and devout,       awaiting the consolation of     Israel, and the holy Spirit was ";
std::string txtJoyful4_3	= "upon him. It had been revealed  to him by the holy Spirit that  he should not see death before  he had seen the Messiah of the  Lord. He came in the Spirit intothe temple; and when the parentsbrought in the child Jesus to   perform the custom of the law inregard to him, he took him into his arms and blessed God,       saying: \"Now, Master, you may   ";
std::string txtJoyful4_4	= "let your servant go in peace,   according to your word, for my  eyes have seen your salvation,  which you prepared in sight of  all the peoples, a light for    revelation to the Gentiles, and glory for your people           Israel.\"The child's father and  mother were amazed at what was  said about him; and Simeon      blessed them and said to Mary   ";
std::string txtJoyful4_5	= "his mother, \"Behold, this child is destined for the fall and    rise of many in Israel, and to  be a sign that will be          contradicted (and you yourself asword will pierce) so that the  thoughts of many hearts may be  revealed.\" There was also a     prophetess, Anna, the daughter  of Phanuel, of the tribe of     Asher. She was advanced in      ";
std::string txtJoyful4_6	= "years, having lived seven years with her husband after her      marriage, and then as a widow   until she was eighty-four. She  never left the temple, but      worshiped night and day with    fasting and prayer. And coming  forward at that very time, she  gave thanks to God and spoke    about the child to all who were awaiting the redemption of      ";
std::string txtJoyful4_7	= "Jerusalem.";

std::string txtJoyful5_1	= "Each year his parents went to   Jerusalem for the feast of      Passover, and when he was twelveyears old, they went up         according to festival custom.   After they had completed its    days, as they were returning,   the boy Jesus remained behind inJerusalem, but his parents did  not know it. Thinking that he   was in the caravan, they        ";
std::string txtJoyful5_2	= "journeyed for a day and looked  for him among their relatives   and acquaintances, but not      finding him, they returned to   Jerusalem to look for him. Afterthree days they found him in thetemple, sitting in the midst of the teachers, listening to them and asking them questions, and  all who heard him were astoundedat his understanding and his    ";
std::string txtJoyful5_3	= "answers. When his parents saw   him, they were astonished, and  his mother said to him, \"Son,   why have you done this to us?   Your father and I have been     looking for you with great      anxiety.\" And he said to them,  \"Why were you looking for me?   Did you not know that I must be in my Father's house?\" But they did not understand what he said ";
std::string txtJoyful5_4	= "to them. He went down with them and came to Nazareth, and was   obedient to them; and his motherkept all these things in her    heart. And Jesus advanced (in)  wisdom and age and favor before God and man.";

std::string txtGloriousSun1_1= "Matthew 28:1-8: After the       sabbath, as the first day of theweek was dawning, Mary Magdaleneand the other Mary came to see  the tomb. And behold, there was a great earthquake; for an angelof the Lord descended from      heaven, approached, rolled back the stone, and sat upon it. His appearance was like lightning   and his clothing was white as   ";
std::string txtGloriousSun1_2= "snow. The guards were shaken    with fear of him and became likedead men. Then the angel said tothe women in reply, \"Do not be  afraid! I know that you are     seeking Jesus the crucified. He is not here, for he has been    raised just as he said. Come andsee the place where he lay. Thengo quickly and tell his         disciples, 'He has been raised  ";
std::string txtGloriousSun1_3= "from the dead, and he is going  before you to Galilee; there youwill see him.' Behold, I have   told you.\" Then they went away  quickly from the tomb, fearful  yet overjoyed, and ran to       announce this to his disciples.";
std::string txtGloriousWed1_1= "When the sabbath was over, Mary Magdalene, Mary, the mother of  James, and Salome bought spices so that they might go and anointhim. Very early when the sun hadrisen, on the first day of the  week, they came to the tomb.    They were saying to one another,\"Who will roll back the stone   for us from the entrance to the tomb?\" When they looked up, they";
std::string txtGloriousWed1_2= "saw that the stone had been     rolled back; it was very large. On entering the tomb they saw a young man sitting on the right  side, clothed in a white robe,  and they were utterly amazed. Hesaid to them, \"Do not be amazed!You seek Jesus of Nazareth, the crucified. He has been raised;  he is not here. Behold the placewhere they laid him. But go and ";
std::string txtGloriousWed1_3= "tell his disciples and Peter,   'He is going before you to      Galilee; there you will see him,as he told you.' Then they wentout and fled from the tomb,     seized with trembling and       bewilderment. They said nothing to anyone, for they were afraid.When he had risen, early on the first day of the week, he       appeared first to Mary          ";
std::string txtGloriousWed1_4= "Magdalene, out of whom he had   driven seven demons. She went   and told his companions who weremourning and weeping. When they heard that he was alive and had been seen by her, they did not  believe. After this he appeared in another form to two of them  walking along on their way to   the country. They returned and  told the others; but they did   ";
std::string txtGloriousWed1_5= "not believe them either. (But)  later, as the eleven were at    table, he appeared to them and  rebuked them for their unbelief and hardness of heart because   they had not believed those who saw him after he had been       raised. He said to them, \"Go    into the whole world and        proclaim the gospel to every    creature. Whoever believes and  ";
std::string txtGloriousWed1_6= "is baptized will be saved;      whoever does not believe will becondemned. These signs will     accompany those who believe: in my name they will drive out     demons, they will speak new     languages. They will pick up    serpents (with their hands), andif they drink any deadly thing, it will not harm them. They willlay hands on the sick, and they ";
std::string txtGloriousWed1_7= "will recover.\"";

std::string txtGloriousSun2_1= "Mark 16:19-20: So then the Lord Jesus, after he spoke to them,  was taken up into heaven and    took his seat at the right hand of God. But they went forth and preached everywhere, while the  Lord worked with them and       confirmed the word through      accompanying signs.";
std::string txtGloriousWed2_1= "Luke 24:44-53: He [Jesus] said  to them, \"These are my words    that I spoke to you while I was still with you, that everything written about me in the law of  Moses and in the prophets and   psalms must be fulfilled.\" Then he opened their minds to        understand the scriptures. And  he said to them, \"Thus it is    written that the Messiah would  ";
std::string txtGloriousWed2_2= "suffer and rise from the dead onthe third day and that          repentance, for the forgiveness of sins, would be preached in   his name to all the nations,    beginning from Jerusalem. You   are witnesses of these things.  And (behold) I am sending the   promise of my Father 12 upon    you; but stay in the city until you are clothed with power from ";
std::string txtGloriousWed2_3= "on high.\" Then he led them (out)as far as Bethany, raised his   hands, and blessed them. As he  blessed them he parted from themand was taken up to heaven. Theydid him homage and then returnedto Jerusalem with great joy, andthey were continually in the    temple praising God.";

std::string txtGlorious3_1	 = "When the time for Pentecost was fulfilled, they were all in one place together. And suddenly    there came from the sky a noise like a strong driving wind, and it filled the entire house in   which they were. Then there     appeared to them tongues as of  fire, which parted and came to  rest on each one of them. And   they were all filled with the   ";
std::string txtGlorious3_2	 = "holy Spirit and began to speak  in different tongues, as the    Spirit enabled them to proclaim.Now there were devout Jews from every nation under heaven       staying in Jerusalem. At this   sound, they gathered in a large crowd, but they were confused   because each one heard them     speaking in his own language.   They were astounded, and in     ";
std::string txtGlorious3_3	 = "amazement they asked, \"Are not  all these people who are        speaking Galileans? Then how    does each of us hear them in hisown native language? We are     Parthians, Medes, and Elamites, inhabitants of Mesopotamia,     Judea and Cappadocia, Pontus andAsia, Phrygia and Pamphylia,    Egypt and the districts of Libyanear Cyrene, as well as         ";
std::string txtGlorious3_4	 = "travelers from Rome, both Jews  and converts to Judaism, Cretansand Arabs, yet we hear them     speaking in our own tongues of  the mighty acts of God.\" They   were all astounded and          bewildered, and said to one     another, \"What does this mean?\" But others said, scoffing, \"Theyhave had too much new wine.\"";

std::string txtGlorious4_1   = "And Mary said: \"My soul         proclaims the greatness of the  Lord; my spirit rejoices in God my savior. For he has looked    upon his handmaid's lowliness;  behold, from now on will all    ages call me blessed. The MightyOne has done great things for   me, and holy is his name. His   mercy is from age to age to     those who fear him. He has shown";
std::string txtGlorious4_2   = "might with his arm, dispersed   the arrogant of mind and heart. He has thrown down the rulers   from their thrones but lifted upthe lowly. The hungry he has    filled with good things; the    rich he has sent away empty. He has helped Israel his servant,  remembering his mercy, accordingto his promise to our fathers,  to Abraham and to his           ";
std::string txtGlorious4_3   = "descendants forever.\"";

std::string txtGlorious5_1   = "A great sign appeared in the    sky, a woman clothed with the   sun, with the moon under her    feet, and on her head a crown oftwelve stars.";

std::string txtSorrowful1_1  = "Then Jesus came with them to a  place called Gethsemane, and he said to his disciples, \"Sit herewhile I go over there and pray.\"He took along Peter and the two sons of Zebedee, and began to   feel sorrow and distress. Then  he said to them, \"My soul is    sorrowful even to death. Remain here and keep watch with me.\" Headvanced a little and fell      ";
std::string txtSorrowful1_2  = "prostrate in prayer, saying, \"MyFather, if it is possible, let  this cup pass from me; yet, not as I will, but as you will.\"    When he returned to his         disciples he found them asleep. He said to Peter, \"So you could not keep watch with me for one  hour? Watch and pray that you   may not undergo the test. The   spirit is willing, but the flesh";
std::string txtSorrowful1_3  = "is weak.\" Withdrawing a second  time, he prayed again, \"My      Father, if it is not possible   that this cup pass without my   drinking it, your will be done!\"Then he returned once more and  found them asleep, for they     could not keep their eyes open. He left them and withdrew again and prayed a third time, saying the same thing again. Then he   ";
std::string txtSorrowful1_4  = "returned to his disciples and   said to them, \"Are you still    sleeping and taking your rest?  Behold, the hour is at hand whenthe Son of Man is to be handed  over to sinners. Get up, let us go. Look, my betrayer is at     hand.\"";

std::string txtSrrwflTue2_1  = "Then he released Barabbas to    them, but after he had Jesus    scourged, he handed him over to be crucified";//Matthew 27:26
std::string txtSrrwflFri2_1  = "So Pilate, wishing to satisfy   the crowd, released Barabbas to them and, after he had Jesus    scourged, handed him over to be crucified.";//Mark 15:15

std::string txtSrrwflTue3_1  = "Matthew 27:27-30: Then the      soldiers of the governor took   Jesus inside the praetorium and gathered the whole cohort aroundhim. They stripped off his      clothes and threw a scarlet     military cloak about him.       Weaving a crown out of thorns,  they placed it on his head, and a reed in his right hand. And   kneeling before him, they mocked";
std::string txtSrrwflTue3_2  = "him, saying, \"Hail, King of the Jews!\" They spat upon him and   took the reed and kept striking him on the head.";

std::string txtSrrwflFri3_1  = "Mark 15:16-20: The soldiers led him away inside the palace, thatis, the praetorium, and         assembled the whole cohort. Theyclothed him in purple and,      weaving a crown of thorns,      placed it on him. They began to salute him with, \"Hail, King of the Jews!\" and kept striking hishead with a reed and spitting   upon him. They knelt before him ";
std::string txtSrrwflFri3_2  = "in homage. And when they had    mocked him, they stripped him ofthe purple cloak, dressed him inhis own clothes, and led him outto crucify him.";

std::string txtSrrwflTue4_1  = "Matthew 27:31-32: And when they had mocked him, they stripped   him of the cloak, dressed him inhis own clothes, and led him offto crucify him. As they were    going out, they met a Cyrenian  named Simon; this man they      pressed into service to carry   his cross.";
std::string txtSrrwflFri4_1  = "Mark 15:21: They pressed into   service a passer-by, Simon, a   Cyrenian, who was coming in fromthe country, the father of      Alexander and Rufus, to carry   his cross.";

std::string txtSrrwflTue5_1  = "Matthew 27:33-56: And when they came to a place called Golgotha (which means Place of the       Skull), they gave Jesus wine to drink mixed with gall. But when he had tasted it, he refused to drink. After they had crucified him, they divided his garments  by casting lots; then they sat  down and kept watch over him    there. And they placed over his ";
std::string txtSrrwflTue5_2  = "head the written charge against him: This is Jesus, the King of the Jews. Two revolutionaries   were crucified with him, one on his right and the other on his  left. Those passing by reviled  him, shaking their heads and    saying, \"You who would destroy  the temple and rebuild it in    three days, save yourself, if   you are the Son of God, (and)   ";
std::string txtSrrwflTue5_3  = "come down from the cross!\"      Likewise the chief priests with the scribes and elders mocked   him and said, \"He saved others; he cannot save himself. So he isthe king of Israel! Let him comedown from the cross now, and we will believe in him. He trusted in God; let him deliver him now if he wants him. For he said, 'Iam the Son of God.'\" The        ";
std::string txtSrrwflTue5_4  = "revolutionaries who were        crucified with him also kept    abusing him in the same way.    From noon onward, darkness came over the whole land until three in the afternoon. And about     three o'clock Jesus cried out ina loud voice, \"Eli, Eli, lema   sabachthani?\" which means, \"My  God, my God, why have you       forsaken me?\" Some of the       ";
std::string txtSrrwflTue5_5  = "bystanders who heard it said,   \"This one is calling for        Elijah.\" Immediately one of themran to get a sponge; he soaked  it in wine, and putting it on a reed, gave it to him to drink.  But the rest said, \"Wait, let ussee if Elijah comes to save     him.\" But Jesus cried out again in a loud voice, and gave up hisspirit. And behold, the veil of ";
std::string txtSrrwflTue5_6  = "the sanctuary was torn in two   from top to bottom. The earth   quaked, rocks were split, tombs were opened, and the bodies of  many saints who had fallen      asleep were raised. And coming  forth from their tombs after hisresurrection, they entered the  holy city and appeared to many. The centurion and the men with  him who were keeping watch over ";
std::string txtSrrwflTue5_7  = "Jesus feared greatly when they  saw the earthquake and all that was happening, and they said,   \"Truly, this was the Son of     God!\" There were many women     there, looking on from a        distance, who had followed Jesusfrom Galilee, ministering to    him. Among them were Mary       Magdalene and Mary the mother ofJames and Joseph, and the mother";
std::string txtSrrwflTue5_8  = "of the sons of Zebedee.";

std::string txtSrrwflFri5_1  = "Mark 15:22-39: They brought him to the place of Golgotha (which is translated Place of the      Skull). They gave him wine      drugged with myrrh, but he did  not take it. Then they crucifiedhim and divided his garments by casting lots for them to see    what each should take. It was   nine o'clock in the morning 10  when they crucified him. The    ";
std::string txtSrrwflFri5_2  = "inscription of the charge       against him read, \"The King of  the Jews.\" With him they        crucified two revolutionaries,  one on his right and one on his left. Those passing by reviled  him, shaking their heads and    saying, \"Aha! You who would     destroy the temple and rebuild  it in three days, save yourself by coming down from the cross.\" ";
std::string txtSrrwflFri5_3  = "Likewise the chief priests, withthe scribes, mocked him among   themselves and said, \"He saved  others; he cannot save himself. Let the Messiah, the King of    Israel, come down now from the  cross that we may see and       believe.\" Those who were        crucified with him also kept    abusing him. At noon darkness   came over the whole land until  ";
std::string txtSrrwflFri5_4  = "three in the afternoon. And at  three o'clock Jesus cried out ina loud voice, \"Eloi, Eloi, lema sabachthani?\" which is          translated, \"My God, my God, whyhave you forsaken me?\" Some of  the bystanders who heard it     said, \"Look, he is calling      Elijah.\" One of them ran, soakeda sponge with wine, put it on a reed, and gave it to him to     ";
std::string txtSrrwflFri5_5  = "drink, saying, \"Wait, let us seeif Elijah comes to take him     down.\" Jesus gave a loud cry andbreathed his last. The veil of  the sanctuary was torn in two   from top to bottom. When the    centurion who stood facing him  saw how he breathed his last he said, \"Truly this man was the   Son of God!\"";

std::string txtLight1_1		 = "2 Corinthians 5:21: For our sakehe made him to be sin who did   not know sin, so that we might  become the righteousness of God in him";

std::string txtLight2_1		 = "John 2:1-12: On the third day   there was a wedding in Cana in  Galilee, and the mother of Jesuswas there. Jesus and his        disciples were also invited to  the wedding. When the wine ran  short, the mother of Jesus said to him, \"They have no wine.\"    (And) Jesus said to her, \"Woman,how does your concern affect me?My hour has not yet come.\" His  ";
std::string txtLight2_2		 = "mother said to the servers, \"Do whatever he tells you.\" Now     there were six stone water jars there for Jewish ceremonial     washings, each holding twenty tothirty gallons. Jesus told them,\"Fill the jars with water.\" So  they filled them to the brim.   Then he told them, \"Draw some   out now and take it to the      headwaiter.\" So they took it.   ";
std::string txtLight2_3		 = "And when the headwaiter tasted  the water that had become wine, without knowing where it came   from (although the servers who  had drawn the water knew), the  headwaiter called the bridegroomand said to him, \"Everyone      serves good wine first, and thenwhen people have drunk freely,  an inferior one; but you have   kept the good wine until now.\"  ";
std::string txtLight2_4		 = "Jesus did this as the beginning of his signs in Cana in Galilee and so revealed his glory, and  his disciples began to believe  in him. After this, he and his  mother, (his) brothers, and his disciples went down to Capernaumand stayed there only a few     days.";

std::string txtLight3_1		 = "Luke 7:47-48: So I tell you, hermany sins have been forgiven;   hence, she has shown great love.But the one to whom little is   forgiven, loves little.\" He saidto her, \"Your sins are          forgiven.\"";

std::string txtLight4_1		 = "Luke 9:35: Then from the cloud  came a voice that said, \"This ismy chosen Son; listen to him.\"";

std::string txtLight5_1		 = "Luke 24:13-35: Now that very daytwo of them were going to a     village seven miles from        Jerusalem called Emmaus, and    they were conversing about all  the things that had occurred.   And it happened that while they were conversing and debating,   Jesus himself drew near and     walked with them, but their eyeswere prevented from recognizing ";
std::string txtLight5_2		 = "him. He asked them, \"What are   you discussing as you walk      along?\" They stopped, looking   downcast. One of them, named    Cleopas, said to him in reply,  \"Are you the only visitor to    Jerusalem who does not know of  the things that have taken placethere in these days?\" And he    replied to them, \"What sort of  things?\" They said to him, \"The ";
std::string txtLight5_3		 = "things that happened to Jesus   the Nazarene, who was a prophet mighty in deed and word before  God and all the people, how our chief priests and rulers both   handed him over to a sentence ofdeath and crucified him. But we were hoping that he would be theone to redeem Israel; and       besides all this, it is now the third day since this took place.";
std::string txtLight5_4		 = "Some women from our group,      however, have astounded us: theywere at the tomb early in the   morning and did not find his    body; they came back and        reported that they had indeed   seen a vision of angels who     announced that he was alive.    Then some of those with us went to the tomb and found things    just as the women had described,";
std::string txtLight5_5		 = "but him they did not see.\" And  he said to them, \"Oh, how       foolish you are! How slow of    heart to believe all that the   prophets spoke! Was it not      necessary that the Messiah      should suffer these things and  enter into his glory?\" Then     beginning with Moses and all theprophets, he interpreted to themwhat referred to him in all the ";
std::string txtLight5_6		 = "scriptures. As they approached  the village to which they were  going, he gave the impression   that he was going on farther.   But they urged him, \"Stay with  us, for it is nearly evening andthe day is almost over.\" So he  went in to stay with them. And  it happened that, while he was  with them at table, he took     bread, said the blessing, broke ";
std::string txtLight5_7		 = "it, and gave it to them. With   that their eyes were opened and they recognized him, but he     vanished from their sight. Then they said to each other, \"Were  not our hearts burning (within  us) while he spoke to us on the way and opened the scriptures tous?\" So they set out at once andreturned to Jerusalem where theyfound gathered together the     ";
std::string txtLight5_8		 = "eleven and those with them who  were saying, \"The Lord has trulybeen raised and has appeared to Simon!\" Then the two recounted  what had taken place on the way and how he was made known to    them in the breaking of the     bread.";

u8 menu_index = 0;//Holds current selection	
u8 menu_extras_index = 0;
u8 score = 0;
u8 health = 100;
u8 lives = 3;
std::string GetDate();

std::string ConvertDayNumToString(int daynum);
std::string GetDayOfWeek();
std::string GetMystery(int indexOfFive);
void DisplayMystery(int indexOfFive);
void StopAllSound();
void wait(int sec);
int GetDayNum(const string &data);
int Room_splash();
int Room_TitleMenu();
int Room_01();
int Room_02();
int Room_03();
int Room_04();
int Room_05();
int Room_06();//fade transition
int Room_07();
int Room_08();
int Room_09();
int Room_10();
int Room_11();
int Room_12();
int Room_13();
int Room_14();
int Room_15();
int Room_16();//Glorybe
int Room_17();
int Room_18();
int Room_19();
int Room_WhatIs();
int Room_Extras();
void DrawMenuButtons();
void FadeAllbgIn();
void FadeAllbgOut();
void RunCredits();
void RunCredits()
{
	//TODO: Calculate center. get string length, /2 - 16
	string credits[22];//(16-(credits[0].length()/2))
	credits[0] = "The RosaryDS v1.3.1.0";
	credits[1] = "";
	credits[2] = "TheRosaryDS.googlecode.com";
	credits[3] = "";
	credits[4] = "Producer: J.P.Socoloski III";
	credits[5] = "";
	credits[6] = "Lead Designer: J.P.Socoloski III";//32
	credits[7] = "";
	credits[8] = "Programmed by: J.P.Socoloski III";
	credits[9] = "";
	credits[10] = "Title Image: Praying Hands and";
	credits[11] = "Rosary by Gail Rein";
	credits[12] = "";
	credits[13] = "Title Song: My Mother's Prayer";
	credits[14] = "";
	credits[15] = "Scripture: New American Bible";
	credits[16] = "www.usccb.org/nab/bible";

    int max = 22;
	int i=0;
	for(i=0;i<max;i++)
	{
		PA_InitText(0, 0);
		PA_SetTextCol(1, 0, 0, 0);//Black
		PA_SetTextCol(0, 0, 0, 0);//Black
		for(int x=0;x<max;x++)
		{
			PA_OutputSimpleText(0, (16-(credits[x].length()/2)), (23-i)+x, credits[x].data());
		}
		wait(1);
		PA_WaitForVBL();
	}
	wait(4);
}
void FadeAllbgIn()
{
	// Transition to normal visible background
	for(s8 i = -31; i <= 0; i++)
	{
		PA_SetBrightness(0, i); 
		PA_SetBrightness(1, i); 
		PA_WaitForVBL();		   
	}
}

void FadeAllbgOut()
{
	// Transition to black
	for(s8 i = 0; i > -32; i--)
	{
		PA_SetBrightness(0, i); 
		PA_SetBrightness(1, i); 
		PA_WaitForVBL();		   
	} 
}

void DrawMenuButtons()
{
	PA_DeleteSprite(0,0);
	PA_DeleteSprite(0,1);
	PA_DeleteSprite(0,2);
	PA_DeleteSprite(0,3);
	PA_DeleteSprite(0,4);
	PA_DeleteSprite(0,5);
	//Now DISPLAY the current index
	if(menu_index == 0)
	{
		PA_CreateSprite(0, 1, (void*)startbuttone_Sprite, OBJ_SIZE_64X32, 1, 1, 99, 18);//enabled...
		PA_CreateSprite(0, 2, (void*)whatis_Sprite, OBJ_SIZE_64X32, 1, 2, 99, 63);//disabled...
		PA_CreateSprite(0, 4, (void*)extrasbutton_Sprite, OBJ_SIZE_64X32, 1, 4, 99, 111);//disabled...

	}
	if(menu_index == 1)
	{
		PA_CreateSprite(0, 0, (void*)startbutton_Sprite, OBJ_SIZE_64X32, 1, 0, 99, 18);//disabled...
		PA_CreateSprite(0, 3, (void*)whatise_Sprite, OBJ_SIZE_64X32, 1, 3, 99, 63);//enabled...
		PA_CreateSprite(0, 4, (void*)extrasbutton_Sprite, OBJ_SIZE_64X32, 1, 4, 99, 111);//disabled...
	}
	if(menu_index == 2)
	{
		PA_CreateSprite(0, 0, (void*)startbutton_Sprite, OBJ_SIZE_64X32, 1, 0, 99, 18);//disabled...
		PA_CreateSprite(0, 2, (void*)whatis_Sprite, OBJ_SIZE_64X32, 1, 2, 99, 63);//disabled...
		PA_CreateSprite(0, 5, (void*)extrasbuttone_Sprite, OBJ_SIZE_64X32, 1, 5, 99, 111);//enabled...
	}

}
std::string GetMystery(int indexOfFive)
{
	std::string mystery   = "";
	int daynum = 0;
	daynum = GetDayNum(GetDate());

	if(daynum == 0 || daynum == 3)
	{
		//mystery.append();//(Wednesdays and Sundays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Glorious Mysteries:         The Resurrection                (Matthew 28:1-8, Mark 16:1-18,  Luke 24:1-12, John 20:1-29)     [Faith]");
			break;
		case 2:
			mystery.append("The Glorious Mysteries:         The Ascension                   (Mark 16:19-20, Luke 24:50-53,  Acts 1:6-11) [Christian Hope]");
			break;
		case 3:
			mystery.append("The Glorious Mysteries:         The Descent of the Holy Ghost   (Acts 2:1-13)                   [Gifts of the Holy Spirit]");
			break;
		case 4:
			mystery.append("The Glorious Mysteries:         The Assumption                  (Luke 1:46–55)                  [To Jesus through Mary]");
			break;
		case 5:
			mystery.append("The Glorious Mysteries:         The Coronation                  (Rev 12:1)                      [Grace of Final Perseverance]");
			break;
		}
	}

	if(daynum == 4)
	{
		//mystery.append("The Luminous Mysteries or Mysteries of Light: ");//(Thursdays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Mysteries of Light:         Jesus' Baptism in the Jordan    (II Corinthians 5:21,Matthew 3:17and parallels)                 [Gratitude for the gift of Faith]");
			break;
		case 2:
			mystery.append("The Mysteries of Light:         Jesus' self-manifestation at    the wedding of Cana (John 2:1- 12)[Fidelity]");
			break;
		case 3:
			mystery.append("The Mysteries of Light:         Jesus' proclamation of the      Kingdom of God, with His call to conversion (Mark 1:15,         Mark 2:3-13; Luke 7:47- 48,     John 20:22-23)                  [Desire for Holiness]");
			break;
		case 4:
			mystery.append("The Mysteries of Light:         Jesus' Transfiguration          (Luke 9:35 and parallels)         [Spiritual Courage]");
			break;
		case 5:
			mystery.append("The Mysteries of Light:         Jesus' institution of the       Eucharist, as the sacramental   expression of the Paschal       Mystery. (Luke 24:13-35 and     parallels, 1 Corinthians        11:24-25) [Love of our          Eucharistic Lord]");
			break;
		}
	}
	if(daynum == 2 || daynum == 5)
	{
		//mystery.append("The Sorrowful Mysteries: ");//(Tuesdays and Fridays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Sorrowful Mysteries:        The Agony in the Garden         (Matthew 26:36-46,Luke 22:39-46) [God's will be done]");
			break;
		case 2:
			mystery.append("The Sorrowful Mysteries:        The Scourging at the Pillar     (Matthew 27:26,Mark 15:15,John19:1)                             [Mortification of the senses]");
			break;
		case 3:
			mystery.append("The Sorrowful Mysteries:        The Crowning with Thorns        (Matthew 27:27-30,Mark 15:16-20,John 19:2) [Reign of Christ     in our heart]");
			break;
		case 4:
			mystery.append("The Sorrowful Mysteries:        The Carrying of the Cross       (Matthew 27:31-32, Mark 15:21,  Luke 23:26-32, John 19:17)      [Patient bearing of trials]");
			break;
		case 5:
			mystery.append("The Sorrowful Mysteries:        The Crucifixion                 (Matthew 27:33-56,Mark 15:22-39,Luke 23:33-49, John 19:17-37)   [Pardoning of Injuries]");
			break;
		}
	}
	if(daynum == 1 || daynum == 6)
	{
		//mystery.append("The Joyful Mysteries: ");//(Mondays and Saturdays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Joyful Mysteries:           The Annunciation                (Luke 1:26-38)");
			break;
		case 2:
			mystery.append("The Joyful Mysteries:           The Visitation                  (Luke 1: 39-56)                  [Love of Neighbor]");
			break;
		case 3:
			mystery.append("The Joyful Mysteries:           The Nativity                    (Luke 2:1-20)                    [Poverty of Spirit]");
			break;
		case 4:
			mystery.append("The Joyful Mysteries:           The Presentation                (Luke 2:21-38)                   [Purity of mind & body]");
			break;
		case 5:
			mystery.append("The Joyful Mysteries:           The Finding of Jesus in the     Temple (Luke 2:41-52)            [Obedience ]");
			break;
		}
	}
	//mystery = ConvertDayNumToString(daynum);
	return mystery;
}
void DisplayMystery(int indexOfFive)
{
	bool FinishedReading = false;
	int daynum = 0;
	daynum = GetDayNum(GetDate());

	if(daynum == 0 || daynum == 3)
	{
		////(Wednesdays and Sundays) The Glorious Mysteries
		switch(indexOfFive)
		{
		case 1:
			if(daynum == 0)
			{
				//Sunday, Matthew 28:1-8...
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtGloriousSun1_1.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtGloriousSun1_2.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_InitCustomText(1, 0, newfont);
				PA_OutputSimpleText(1,0,12, txtGloriousSun1_3.data());
			}
			else
			{
				//Wed...
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_1.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_2.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_3.data());
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_4.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_5.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_6.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_7.data());
			}
			FinishedReading = true;
			break;
		case 2:
			if(daynum == 0)
			{
				//Sunday, Mark 16:19-20
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed2_1.data());
			}
			else
			{
				//Wed, Luke 24:44-53...
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_1.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_2.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtGloriousWed1_3.data());
			}
			FinishedReading = true;
			break;
		case 3:
			//Both Acts 2:1-13...
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtGlorious3_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtGlorious3_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtGlorious3_3.data());
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtGlorious3_4.data());
			FinishedReading = true;
			break;
		case 4:
			//Both Luke 1:46–55...
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtGlorious4_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtGlorious4_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtGlorious4_3.data());
			FinishedReading = true;
			break;
		case 5:
			//Both Rev 12:1  The Coronation...
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtGlorious5_1.data());
			FinishedReading = true;
			break;
		}
	}

	if(daynum == 4)
	{
		//mystery.append("The Luminous Mysteries or Mysteries of Light: ");//(Thursdays)
		switch(indexOfFive)
		{
		case 1:
			//...
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight1_1.data());
			FinishedReading = true;
			break;
		case 2:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight2_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight2_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight2_3.data());
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight2_4.data());
			FinishedReading = true;
			break;
		case 3:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight3_1.data());
			FinishedReading = true;
			break;
		case 4:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight4_1.data());
			FinishedReading = true;
			break;
		case 5:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_1.data()); 
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_3.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_4.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_5.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_6.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_7.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtLight5_8.data());
			FinishedReading = true;
			break;
		}
	}
	if(daynum == 2 || daynum == 5)
	{
		//mystery.append("The Sorrowful Mysteries: ");//(Tuesdays and Fridays)
		switch(indexOfFive)
		{
		case 1:
			//Matthew 26:36-46...
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtSorrowful1_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtSorrowful1_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtSorrowful1_3.data());
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtSorrowful1_4.data());
			break;
		case 2:
			if(daynum == 2)
			{
				//Matthew 27:26...
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue2_1.data()); 
			}
			else
			{
				//Mark 15:15
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri2_1.data()); 
			}
			FinishedReading = true;
			break;
		case 3:
			if(daynum == 2)
			{
				//Matthew 27:27-30...
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue3_1.data()); 
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue3_2.data());
			}
			else
			{
				//Mark 15:16-20
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri3_1.data()); 
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri3_2.data());
			}
			FinishedReading = true;
			break;
		case 4:
			if(daynum == 2)
			{
				//Matthew 27:26...
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue4_1.data()); 
			}
			else
			{
				//Mark 15:15
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri4_1.data()); 
			}
			FinishedReading = true;
			break;
		case 5:
			if(daynum == 2)
			{
				//Matthew 27:31...
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_1.data()); 
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_2.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_3.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_4.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_5.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_6.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_7.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflTue5_8.data());
			}
			else
			{
				//Mark 15:22-39
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri5_1.data()); 
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri5_2.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri5_3.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri5_4.data());
				PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtSrrwflFri5_5.data());
			}
			FinishedReading = true;
			break;
		}
	}
	if(daynum == 1 || daynum == 6)
	{
		//mystery.append("The Joyful Mysteries: ");//(Mondays and Saturdays)
		switch(indexOfFive)
		{
		case 1:
			//Draw and new text
			PA_EasyBgLoad(1, 2, RosaryTopMix);
			PA_OutputSimpleText(1,0,12, txtJoyful1_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(1, 2, RosaryTopMix);
			PA_OutputSimpleText(1,0,12, txtJoyful1_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(1, 2, RosaryTopMix);
			PA_OutputSimpleText(1,0,12, txtJoyful1_3.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(1, 2, RosaryTopMix);
			PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
			PA_OutputSimpleText(1,0,12, txtJoyful1_4.data());
			FinishedReading = true;
			break;
		case 2:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful2_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful2_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful2_3.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful2_4.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtJoyful2_5.data());
			FinishedReading = true;
			break;
		case 3:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful3_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful3_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful3_3.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful3_4.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtJoyful3_5.data());
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful3_6.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtJoyful3_7.data());
			FinishedReading = true;
			break;
		case 4:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful4_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful4_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful4_3.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful4_4.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtJoyful4_5.data());
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful4_6.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_InitCustomText(0, 0, newfont);
			PA_OutputSimpleText(0,0,12, txtJoyful4_7.data());
			FinishedReading = true;
			break;
		case 5:
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful5_1.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful5_2.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful5_3.data());
			PA_WaitFor((PA_SpriteTouched(1)) || (Pad.Newpress.A));//Next pressed
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtJoyful5_4.data());
			FinishedReading = true;
			break;
		}
	}
}
std::string GetDayOfWeek()
{
	return ConvertDayNumToString(GetDayNum(GetDate()));
}
int GetDayNum(const string &data)
{
	int month,day,year,dm,dn,leap;

	stringstream buffer(data.substr(0,2));
	buffer >> month;

	stringstream buffer2(data.substr(3,5));
	buffer2 >> day;

	stringstream buffer3(data.substr(6,8));
	buffer3 >> year;
	//PA_OutputText(1, 2, 18, "%02d/%02d/%02d", month, day, year);
     int CalendarSystem = 1; //1 for Gregorian Calendar//0=Julian Calendar//http://everything2.com
     if (month < 3)
     {
           month = month + 12;
           year = year - 1;
     }
     return (
             day
             + (2 * month)
             + int(6 * (month + 1) / 10)
             + year
             + int(year / 4)
             - int(year / 100)
             + int(year / 400)
             + CalendarSystem
            ) % 7;
}                  

int leap (int year)
{
	if((year%100== 0 && year%400==0)||  (year%4==0))

		return 1;
	else
		return 0;
}

std::string GetDate(void)
{
	// convert MM/DD/YY into a string
    std::string Date = "";
	char datechar[9];
	sprintf(datechar, "%02d/%02d/%02d", PA_RTC.Month, PA_RTC.Day, PA_RTC.Year);
	Date.append(datechar);
	return Date;
}

std::string ConvertDayNumToString(int daynum)
{
	std::string DayOfWeek = "";
	switch(daynum)
	{
	case 0:
		DayOfWeek = "Sunday";
		break;
	case 1:
		DayOfWeek = "Monday";
		break;
	case 2:
		DayOfWeek = "Tuesday";
		break;
	case 3:
		DayOfWeek = "Wednesday";
		break;
	case 4:
		DayOfWeek = "Thursday";
		break;
	case 5:
		DayOfWeek = "Friday";
		break;
	case 6:
		DayOfWeek = "Saturday";
		break;
	}
	return DayOfWeek;
}
void wait(int sec)
{
	int time=0;
	for(time=0;time<60*sec;time++)
	{
		PA_WaitForVBL();
	}
}

int main (void)
{
	PA_Init();
	PA_InitVBL();
	PA_InitText(0, 0);
	PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
	Room_splash();
}
void ChkForStart()
{
	//This should be called in a loop to go back to Room_TitleMenu
	if(Pad.Newpress.Start)
	{
		StopAllSound();
		Room_TitleMenu();
	}
}
void StopAllSound()
{
	for(int channel = 0; channel < 16; channel++)
	{			
		PA_StopSound(channel);
	}
	PA_WaitForVBL();
}

void ReloadRosaryRoom()
{
	//Reset both screens and the sprites to redraw anything
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	PA_LoadSpritePal(1, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(0, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(1, 4, (void*)next_Pal);
	PA_LoadSpritePal(0, 4, (void*)next_Pal);
	PA_EasyBgLoad(1, 2, RosaryTop);
	PA_EasyBgLoad(0, 2, RosaryBottom);
	PA_CreateSprite(0, 0, (void*)praywithme_Sprite, OBJ_SIZE_64X32, 1, 3, 13, 50);
	PA_CreateSprite(0, 1, (void*)next_Sprite, OBJ_SIZE_64X32, 1, 4, 192, 50);
	PA_InitText(0, 0);
	PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
}
void ReloadRosaryRoomRev()
{
	//Reset both screens and the sprites to redraw anything
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	PA_LoadSpritePal(1, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(0, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(1, 4, (void*)next_Pal);
	PA_LoadSpritePal(0, 4, (void*)next_Pal);
	PA_EasyBgLoad(1, 2, RosaryTop);
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_CreateSprite(0, 0, (void*)praywithme_Sprite, OBJ_SIZE_64X32, 1, 3, 13, 50);
	PA_CreateSprite(0, 1, (void*)next_Sprite, OBJ_SIZE_64X32, 1, 4, 192, 50);
				PA_InitText(1, 0);
				PA_InitCustomText(0, 0, newfont);
}
int Room_splash(void) 
{
	PA_ResetBgSys();
	PA_ResetSpriteSys();

	AS_SetDefaultSettings(AS_PCM_8BIT, 11025,AS_NO_DELAY);
	PA_InitASLibForMP3(AS_MODE_MP3 | AS_NO_DELAY | AS_MODE_8CH);
	//PA_InitCustomText(1, 0, newfont); 
	//PA_InitCustomText(0, 0, newfont); 

	PA_SetBrightness(0, -31); // all black
	PA_SetBrightness(1, -31); // all black	

	PA_EasyBgLoad(1, 2, JSDSSplash);
	PA_EasyBgLoad(0, 2, JSDSCopyright);

	// Transition to normal visible background
	FadeAllbgIn();

	//== PLAY SPLASH SOUND ==//
	if (finished == FALSE) 
	{
		PA_PlaySimpleSound(jsds_intro);
		finished = TRUE;
	}

	//== WAIT 8 BEFORE MOVING ON ==//
	wait(5);

	// Transition to black
	FadeAllbgOut();

	// Now that it's all black, clean all that and you're ready to go !
	PA_ResetBgSys();
	PA_SetBrightness(0, 0); // normal
	PA_SetBrightness(1, 0); // normal	
	//========= END OF SPLASH SCREEN ===========//

	Room_TitleMenu();
	//Room_18();//DEBUG LINE
	PA_CheckLid();
	PA_WaitForVBL();
	return 0;
}
int Room_TitleMenu(void) 
{
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	//PA_InitCustomText(1, 0, newfont); 
	//PA_InitCustomText(0, 0, newfont); 
	PA_LoadSpritePal(1, 0, (void*)startbutton_Pal);
	PA_LoadSpritePal(0, 0, (void*)startbutton_Pal);
	PA_LoadSpritePal(1, 1, (void*)startbuttone_Pal);
	PA_LoadSpritePal(0, 1, (void*)startbuttone_Pal);
	PA_LoadSpritePal(1, 2, (void*)whatis_Pal);
	PA_LoadSpritePal(0, 2, (void*)whatis_Pal);
	PA_LoadSpritePal(1, 3, (void*)whatise_Pal);
	PA_LoadSpritePal(0, 3, (void*)whatise_Pal);
	PA_LoadSpritePal(1, 4, (void*)extrasbutton_Pal);
	PA_LoadSpritePal(0, 4, (void*)extrasbutton_Pal);
	PA_LoadSpritePal(1, 5, (void*)extrasbuttone_Pal);
	PA_LoadSpritePal(0, 5, (void*)extrasbuttone_Pal);
	PA_LoadSpritePal(1, 6, (void*)creditsbutton_Pal);
	PA_LoadSpritePal(0, 6, (void*)creditsbutton_Pal);
	PA_LoadSpritePal(1, 7, (void*)creditsbuttone_Pal);
	PA_LoadSpritePal(0, 7, (void*)creditsbuttone_Pal);

	PA_EasyBgLoad(1, 2, RosaryDSTitle);
	PA_EasyBgLoad(0, 2, RosaryDSMenuBkg);
	PA_CreateSprite(0, 1, (void*)startbuttone_Sprite, OBJ_SIZE_64X32, 1, 1, 99, 18);
	PA_CreateSprite(0, 2, (void*)whatis_Sprite, OBJ_SIZE_64X32, 1, 2, 99, 63);
	PA_CreateSprite(0, 4, (void*)extrasbutton_Sprite, OBJ_SIZE_64X32, 1, 4, 99, 111);
	menu_index = 0;//must reset

	//Start room all black and fade in
	PA_SetBrightness(0, -31); // all black
	PA_SetBrightness(1, -31); // all black	
	FadeAllbgIn();

	PA_PlaySimpleSound(HymnMyMothersPrayer);

	while(1) 
	{
		///////////////////////////////////////////////////////////////////////////////////
		//Select the first sprite
		if(Pad.Newpress.Down)
		{
			PA_PlaySimpleSound(click);
			//OBJ_SIZE_64X32
			if(menu_index != 2)
			{
				menu_index = menu_index + 1;
			}
			else
			{
				//menu_index = x so go back to 0
				menu_index = 0;
			}
			DrawMenuButtons();
		}
		if(Pad.Newpress.Up)
		{
			PA_PlaySimpleSound(click);
			if(menu_index != 0)
			{
				menu_index = menu_index - 1;
			}
			else
			{
				if(menu_index == 0)
				{
					//menu_index = 0 so advance to 2
					menu_index = 2;
				}
				else
					menu_index = menu_index - 1;
			}
			DrawMenuButtons();
		}
		///////////////////////////////////////////////////////////////////////////////////
		//Make selection by Stylus...
		if (PA_SpriteTouched(0) || PA_SpriteTouched(1)) 
		{	//menu_index == 0
			StopAllSound();
			// Transition to black
			FadeAllbgOut();
			Room_01();
		}
		if (PA_SpriteTouched(2) || PA_SpriteTouched(3)) 
		{	//menu_index == 1
			StopAllSound();
			Room_WhatIs();
		}
		if (PA_SpriteTouched(4) || PA_SpriteTouched(5)) 
		{	//menu_index == 2
			StopAllSound();
			Room_Extras();
		}

		/////Make selection by A button...
		if(Pad.Newpress.A)
		{
			//Get the menu_index
			if(menu_index == 0)
			{
				StopAllSound();
				// Transition to black
				FadeAllbgOut();
				Room_01();
			}
			if(menu_index == 1)
			{
				StopAllSound();
				Room_WhatIs();
			}
			if(menu_index == 2)
			{
				StopAllSound();
				Room_Extras();
			}
		}

		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_01(void) 
{
	ReloadRosaryRoom();
	int touched = 0;
	// Transition to visible
	FadeAllbgIn();

	//Step1
	PA_PlaySimpleSound(step1);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,5,19,"START->");//First part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtApostlesC_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(TheApostlesCreed);
		}
		
		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			touched = touched + 1;
			//PA_OutputText(0,0,1,"touched : %d", touched);//DEBUGGING
			if(touched >= 2)
			{
				StopAllSound();
				Room_02();
			}
			else
			{
				//Draw RosaryTopMix and new text
				PA_ResetBgSysScreen(1);
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
				PA_OutputSimpleText(1,0,12, txtApostlesC_2.data());
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_02(void) 
{
	ReloadRosaryRoom();

	//Step2
	PA_PlaySimpleSound(step2);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,12,15,"2->");//2nd part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtOurFather_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_03();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_03(void) 
{
	ReloadRosaryRoom();
	int touched = 0;

	//Step3
	PA_PlaySimpleSound(step3);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,13,13,"3->");//3rd part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//3 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,13,12,"3->");//3rd part of rosary
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,13,10,"3->");//3rd part of rosary
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				Room_04();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_04(void) 
{
	ReloadRosaryRoom();

	//Step4
	PA_PlaySimpleSound(step4);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,13,9,"4->");//2nd part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_05();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}


int Room_05(void) 
{
	ReloadRosaryRoom();
	int touched = 0;

	//Step5
	PA_PlaySimpleSound(step5);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,12,8,"5->");//5th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(1,0,13, GetMystery(1).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
				PA_OutputSimpleText(1,0,12, txtOurFather_1.data());
				PA_PlaySimpleSound(OurFather);
			}
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				DisplayMystery(1);//writes text until completed
			}
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
				PA_OutputSimpleText(1,0,12, txtOurFather_1.data());
			}
			if(touched == 3)
			{
				PA_InitCustomText(1, 0, newfont);//PA_InitCustomText(1, 0, newfont);//PA_InitText(1, 0);
				Room_06();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_06(void) 
{
	ReloadRosaryRoom();
	int touched = 0;

	//Step5
	PA_PlaySimpleSound(step6);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,8,5,"6->");//6th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,7,4,"6->");//5th part of rosary[2/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,6,3,"6->");//6th part of rosary[3/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,5,2,"6->");//6th part of rosary[4/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,4,1,"6->");//6th part of rosary[5/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,3,0,"6->");//6th part of rosary[6/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			//TOP SCREEN! 
			if(touched == 6)
			{
				//===TRANSITION===//
				// Transition to black
				FadeAllbgOut();
				PA_ResetBgSys();
				PA_ResetSpriteSys();
				//Redraw everything with textbox on bottom
				ReloadRosaryRoomRev();
				// Transition to normal visible background
				FadeAllbgIn();
				//===TRANSITION===//
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,3,23,"6->");//6th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,2,22,"6->");//6th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,21,"6->");//6th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,20,"6->");//6th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_07();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_07(void) 
{
	ReloadRosaryRoomRev();
	//Step7
	PA_PlaySimpleSound(step7);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,1,19,"7->");//7th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_08();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_08(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step8
	PA_PlaySimpleSound(step8);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,0,18,"8->");//8th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(2).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
				PA_PlaySimpleSound(OurFather);
			}
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				DisplayMystery(2);//writes text until completed
			}
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 3)
			{
				PA_InitCustomText(0, 0, newfont);
				Room_09();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_09(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step9
	PA_PlaySimpleSound(step9);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,0,17,"9->");//9th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,16,"9->");//9th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,14,"9->");//9th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,13,"9->");//9th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,12,"9->");//9th part of rosary[5/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,10,"9->");//9th part of rosary[6/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			//TOP SCREEN! 
			if(touched == 6)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,9,"9->");//9th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,8,"9->");//9th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,7,"9->");//9th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,6,"9->");//9th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_10();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_10(void) 
{
	ReloadRosaryRoomRev();

	//Step10
	PA_PlaySimpleSound(step10);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,1,5,"10->");//10th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_11();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_11(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step10
	PA_PlaySimpleSound(step11);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,1,4,"11->");//11th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(3).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			if(touched == 2)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
				PA_PlaySimpleSound(OurFather);
			}
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				DisplayMystery(3);//writes text until completed
			}
			if(touched == 2)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 3)
			{
				PA_InitCustomText(0, 0, newfont);
				Room_12();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_12(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step9
	PA_PlaySimpleSound(step12);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,2,3,"12->");//12th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,4,2,"12->");//9th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,6,2,"12->");//9th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,8,1,"12->");//9th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,10,0,"12->");//9th part of rosary[5/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,13,0,"12->");//9th part of rosary[6/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			//TOP SCREEN! 
			if(touched == 6)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,20,1,"<-12");//9th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,22,1,"<-12");//9th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,24,2,"<-12");//9th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,26,3,"<-12");//9th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_13();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_13(void) 
{
	ReloadRosaryRoomRev();
	//Step13
	PA_PlaySimpleSound(step13);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,26,3,"<-13");//13th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_14();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_14(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step14
	PA_PlaySimpleSound(step14);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,4,"<-14");//11th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(4).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			if(touched == 2)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
				PA_PlaySimpleSound(OurFather);
			}
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				DisplayMystery(4);//writes text until completed
			}
			if(touched == 2)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 3)
			{
				PA_InitCustomText(0, 0, newfont);
				Room_15();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_15(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step15
	PA_PlaySimpleSound(step15);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,5,"<-15");//12th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,7,"<-15");//15th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,8,"<-15");//15th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,9,"<-15");//15th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,10,"<-15");//15th part of rosary[5/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,11,"<-15");//15th part of rosary[6/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 6)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,13,"<-15");//15th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,14,"<-15");//15th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,15,"<-15");//15th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,16,"<-15");//15th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_16();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_16(void) 
{
	ReloadRosaryRoomRev();
	//Step16
	PA_PlaySimpleSound(step16);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,17,"<-16");//16th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_17();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}


int Room_17(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step17
	PA_PlaySimpleSound(step17);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,18,"<-17");//17th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(5).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			if(touched == 2)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
				PA_PlaySimpleSound(OurFather);
			}
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				DisplayMystery(5);//writes text until completed
			}
			if(touched == 2)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_InitCustomText(0, 0, newfont);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 3)
			{
				PA_InitCustomText(0, 0, newfont);
				Room_18();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_18(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step18
	PA_PlaySimpleSound(step18);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,19,"<-18");//18th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,21,"<-18");//18th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,22,"<-18");//18th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,23,"<-18");//18th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//===TRANSITION===//
				// Transition to black
				FadeAllbgOut();
				PA_ResetBgSys();
				PA_ResetSpriteSys();
				//Redraw everything with textbox on bottom
				ReloadRosaryRoom();

				// Transition to normal visible background
				FadeAllbgIn();
				//===TRANSITION===//

				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,28,0,"<-18");//18th part of rosary[5/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,27,1,"<-18");//18th part of rosary[6/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 6)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,26,2,"<-18");//18th part of rosary[7/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,25,3,"<-18");//18th part of rosary[8/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,24,4,"<-18");//18th part of rosary[9/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,23,5,"<-18");//18th part of rosary[10/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_19();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_19(void) 
{
	ReloadRosaryRoom();
	//Step19
	PA_PlaySimpleSound(step19);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,22,5,"<-19");//19th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_TitleMenu();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}


int Room_WhatIs(void)
{
	//===TRANSITION===//
	// Transition to black
	FadeAllbgOut();
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	//Redraw 
	PA_EasyBgLoad(1, 2, RosaryDSMenuBkg);
	PA_EasyBgLoad(0, 2, RosaryDSMenuBkg);
	PA_InitText(1, 0);
	PA_InitText(0, 0);
	PA_SetTextCol(1, 0, 0, 0);//Black
	PA_SetTextCol(0, 0, 0, 0);//Black

	// Transition to normal visible background
	FadeAllbgIn();
	//===TRANSITION===//

	PA_PlaySimpleSound(TheRosaryIs);
	PA_OutputSimpleText(1, 5, 2, "What is the Rosary?");
	PA_OutputSimpleText(1, 0, 16, "The Rosary is made up of twenty \"mysteries\" (significant events or moments in the life of Jesus and Mary), which, following the Apostolic Letter Rosarium       Virginis Mariae, are grouped    into four series.");
	PA_OutputSimpleText(0, 0, 2,"The first contains joyful       mysteries (recited on Mondays   and Saturdays); the second, the mysteries of light (Thursdays); the third, the sorrowful        mysteries (Tuesdays and         Fridays); and the fourth, the   glorious mysteries (Wednesdays  and Sundays).");
	PA_OutputSimpleText(0,3,23, "*touch screen to go back*");

	while(1) 
	{
		if(Pad.Newpress.B || Stylus.Newpress)
		{
			StopAllSound();//Stop duplicate plays
			Room_TitleMenu();
		}
	}
}


void DrawExtrasMenu()
{
		if(menu_index == 0)
		{
			PA_OutputSimpleText(1, 6, 6, "* Quotes about the Rosary");
			PA_OutputSimpleText(1, 6, 8, "  Hymns");
			PA_OutputSimpleText(1, 6, 10, "  Credits");
		}
		if(menu_index == 1)
		{
			PA_OutputSimpleText(1, 6, 6, "  Quotes about the Rosary");
			PA_OutputSimpleText(1, 6, 8, "* Hymns");
			PA_OutputSimpleText(1, 6, 10, "  Credits");
		}
		if(menu_index == 2)
		{
			PA_OutputSimpleText(1, 6, 6, "  Quotes about the Rosary");
			PA_OutputSimpleText(1, 6, 8, "  Hymns");
			PA_OutputSimpleText(1, 6, 10, "* Credits");
		}
		PA_OutputSimpleText(1, 0, 23, "(press Up/Down then A to select)");//directions
		//PA_WaitForVBL();//causes delays
}
void DrawHymnsMenu()
{
		if(menu_extras_index == 0)
		{
			PA_OutputSimpleText(0, 6, 6,  "* For All the Saints");
			PA_OutputSimpleText(0, 6, 8,  "  My Mother's Prayer");
			PA_OutputSimpleText(0, 6, 10, "  What Grace, O Lord, and          Beauty Shone");
		}
		if(menu_extras_index == 1)
		{
			PA_OutputSimpleText(0, 6, 6,  "  For All the Saints");
			PA_OutputSimpleText(0, 6, 8,  "* My Mother's Prayer");
			PA_OutputSimpleText(0, 6, 10, "  What Grace, O Lord, and          Beauty Shone");
		}
		if(menu_extras_index == 2)
		{
			PA_OutputSimpleText(0, 6, 6,  "  For All the Saints");
			PA_OutputSimpleText(0, 6, 8,  "  My Mother's Prayer");
			PA_OutputSimpleText(0, 6, 10, "* What Grace, O Lord, and          Beauty Shone");
		}
		PA_WaitForVBL();
}
void DrawQuotesMenu()
{
		PA_InitText(0, 0);
		PA_SetTextCol(0, 0, 0, 0);//Black
		//Quotes about the Rosary
		if(menu_extras_index == 0)
		{
			PA_OutputSimpleText(0, 6, 1,  "* Sister Lucia");
			PA_OutputSimpleText(0, 6, 3,  "  Bishop Hugh Doyle");
			PA_OutputSimpleText(0, 6, 5,  "  Lacordaire");
		}
		if(menu_extras_index == 1)
		{
			PA_OutputSimpleText(0, 6, 1,  "  Sister Lucia");
			PA_OutputSimpleText(0, 6, 3,  "* Bishop Hugh Doyle");
			PA_OutputSimpleText(0, 6, 5,  "  Lacordaire");
		}
		if(menu_extras_index == 2)
		{
			PA_OutputSimpleText(0, 6, 1,  "  Sister Lucia");
			PA_OutputSimpleText(0, 6, 3,  "  Bishop Hugh Doyle");
			PA_OutputSimpleText(0, 6, 5,  "* Lacordaire");
		}
		PA_WaitForVBL();
}
int Room_Extras(void)
{
	//===TRANSITION===//
	// Transition to black
	FadeAllbgOut();
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	//Redraw 
	PA_EasyBgLoad(1, 2, RosaryDSMenuBkg);
	PA_EasyBgLoad(0, 2, RosaryDSMenuBkg);
	PA_InitText(0, 0);
	PA_InitText(1, 0);
	PA_SetTextCol(1, 0, 0, 0);//Black
	PA_SetTextCol(0, 0, 0, 0);//Black

	// Transition to normal visible background
	FadeAllbgIn();
	//===TRANSITION===//
	menu_index = 0;
	string cntrstrs[10];//(16-(cntrstrs[0].length()/2))
	cntrstrs[0] = "EXTRAS";
	//cntrstrs[1] = ;

	while(1) 
	{
		PA_InitText(1, 0);
		PA_InitText(0, 0);
		PA_SetTextCol(1, 0, 0, 0);//Black
		PA_SetTextCol(0, 0, 0, 0);//Black
		PA_OutputSimpleText(1, (16-(cntrstrs[0].length()/2)), 2, cntrstrs[0].data());//Extras
		DrawExtrasMenu();

		///////////////////////////////////////////////////////////////////////////////////
		//Go back to mainmenu
		if(Pad.Newpress.B || Pad.Newpress.Start)
		{
			StopAllSound();//Stop duplicate plays
			Room_TitleMenu();
		}
		//Select the first sprite
		if(Pad.Newpress.Down)
		{
			PA_PlaySimpleSound(click);
			if(menu_index != 2)
			{
				menu_index = menu_index + 1;
			}
			else
			{
				//menu_index = x so go back to 0
				menu_index = 0;
			}
			DrawExtrasMenu();
		}
		if(Pad.Newpress.Up)
		{
			PA_PlaySimpleSound(click);
			if(menu_index != 0)
			{
				menu_index = menu_index - 1;
			}
			else
			{
				if(menu_index == 0)
				{
					//menu_index = 0 so advance to 2
					menu_index = 2;
				}
				else
					menu_index = menu_index - 1;
			}
			DrawExtrasMenu();
		}
		if(Pad.Newpress.A)
		{
			PA_PlaySimpleSound(click);
			if(menu_index == 0)
			{
				//=======Quotes about the Rosary
				DrawQuotesMenu();
				menu_extras_index = 0;
				//Stay in this menu
				while(1)
				{
					if(Pad.Newpress.Down)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 2)
						{
							menu_extras_index = menu_extras_index + 1;
						}
						else
						{
							//menu_extras_index = x so go back to 0
							menu_extras_index = 0;
						}
						DrawQuotesMenu();
					}
					if(Pad.Newpress.Up)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 0)
						{
							menu_extras_index = menu_extras_index - 1;
						}
						else
						{
							if(menu_extras_index == 0)
							{
								//menu_extras_index = 0 so advance to 2
								menu_extras_index = 2;
							}
							else
								menu_extras_index = menu_extras_index - 1;
						}
						DrawQuotesMenu();
					}
					if(Pad.Newpress.A)
					{
						StopAllSound();
						if(menu_extras_index == 0)
						{
							//Sister Lucia
							PA_OutputSimpleText(0, 0, 8,  "--------------------------------");
							PA_OutputSimpleText(0, 0, 9,"\"My impression is that the      Rosary is of the greatest value not only according to the words of Our Lady of Fatima, but      according to the effects of the Rosary one sees throughout      history. My impression is that  Our Lady wanted to give ordinarypeople, who might not know how  to pray, this simple  method of getting closer to God.\" -Sister Lucia, one of the seers of      Fatima");
						}
						if(menu_extras_index == 1)
						{
							//Bishop Hugh Doyle
							PA_OutputSimpleText(0, 0, 8,  "--------------------------------");
							PA_OutputSimpleText(0, 0, 9,"\"No one can live continually in sin and continue to say the     Rosary: either they will give upsin or they will give up the    Rosary.\" -Bishop Hugh Doyle");
						}
						if(menu_extras_index == 2)
						{
							//Lacordaire
							PA_OutputSimpleText(0, 0, 8,  "--------------------------------");
							PA_OutputSimpleText(0, 0, 9,"\"For Christians, the first of   books is the Gospel and the     Rosary is actually the          abridgement of the Gospel.\"     -Lacordaire");
						
						}
					}
					//Go back to mainmenu
					if(Pad.Newpress.B || Pad.Newpress.Start)
					{
						StopAllSound();//Stop duplicate plays
						//erase menu text
						PA_InitText(0, 0);
						PA_SetTextCol(0, 0, 0, 0);//Black
						break;
					}
				}
			}
			if(menu_index == 1)
			{
				//========Hymns
				menu_extras_index = 0;
				DrawHymnsMenu();
				//Stay in this menu
				while(1)
				{
					if(Pad.Newpress.Down)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 2)
						{
							menu_extras_index = menu_extras_index + 1;
						}
						else
						{
							//menu_extras_index = x so go back to 0
							menu_extras_index = 0;
						}
						DrawHymnsMenu();
					}
					if(Pad.Newpress.Up)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 0)
						{
							menu_extras_index = menu_extras_index - 1;
						}
						else
						{
							if(menu_extras_index == 0)
							{
								//menu_extras_index = 0 so advance to 2
								menu_extras_index = 2;
							}
							else
								menu_extras_index = menu_extras_index - 1;
						}
						DrawHymnsMenu();
					}
					if(Pad.Newpress.A)
					{
						StopAllSound();
						if(menu_extras_index == 0)
						{
							//PA_OutputSimpleText(0, 6, 6,  "* For All the Saints");
							PA_PlaySimpleSound(HymnForAlltheSaints);
						}
						if(menu_extras_index == 1)
						{
							//PA_OutputSimpleText(0, 6, 8,  "* My Mother's Prayer");
							PA_PlaySimpleSound(HymnMyMothersPrayer);
						}
						if(menu_extras_index == 2)
						{
							//PA_OutputSimpleText(0, 6, 10, "* What Grace, O Lord, and Beauty Shone");
							PA_PlaySimpleSound(HymnWhatGrace);
						}
					}
					//Go back to mainmenu
					if(Pad.Newpress.B || Pad.Newpress.Start)
					{
						StopAllSound();//Stop duplicate plays
						//erase menu text
						PA_InitText(0, 0);
						PA_SetTextCol(0, 0, 0, 0);//Black
						break;
					}
				}
			}
			if(menu_index == 2)
			{	//======Credits
				PA_PlaySimpleSound(HymnWhatGrace);
				RunCredits();
			}
		}
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
