#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <algorithm>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnWidth(0, 100);
    ui->treeWidget->setColumnWidth(1, 150);
    ui->treeWidget->setColumnWidth(2, 500);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_aes_btn_crypt_clicked()
{
    QProcess p;
    QStringList params;

    QString text = ui->aes_crypt->toPlainText();
    QString password = ui->aes_pass_left->text();
  //  std:replace( text.begin(), text.end(), ' ', '&#032;');
    params << "/home/jan/Dokumente/PU/AES/Rijndael.py" << "-m=e" << "-p=" + password << "-t=" + text;
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("python", params);
    p.waitForFinished(-1);

    QString p_stdout = p.readAll(); //Still getting all, not just stdout

    ui->aes_crypt->setPlainText(p_stdout);

}

void mainWindow::on_aes_btn_decrypt_clicked()
{
    QProcess p;
    QStringList params;

    QString text = ui->aes_decrypt->toPlainText();
    QString password = ui->aes_pass_right->text();
  //  std:replace( text.begin(), text.end(), '&#032;', ' ');
    params << "/home/jan/Dokumente/PU/AES/Rijndael.py" << "-m=d" << "-p=" + password << "-t=" + text;
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("python", params);
    p.waitForFinished(-1);

    QString p_stdout = p.readAll(); //Still getting ayll, not just stdout

    ui->aes_decrypt->setPlainText(p_stdout);

}

// params << "/home/jan/Dokumente/PU/ElGamal/ElGamal.py" << "-t=1" << "-p=1234567890123456" << "-k=barKey";
// params << "/home/jan/Dokumente/PU/ElGamal/ElGamal.py" << "-t=3" << "-poc=0.03183499909124645700016732113916381456690068234211755046889747249946205498188511041090926110050984673504934990270823695719198688631424384874708382021688084814646137999776588037490003154649875419849070249533885277843832652940788730476789198594969946596847917229675169912104422840360568261419998852797956729340937563564371960285389034063234374876315784339850220971894847832422233198859832454553746587076761021089036200316629893438138073262170536012198264028885976940947915997397036955106498717777129753521048455497308874110400018865257466403433149634166163443545785586278134020961156354587867467590536823229317634735700268604428418542878634411204437000163089901658647532975807330254234588003645255986751580788016153908073101091210445903986971133878565400351002302224698870458328968956042763700024907124779182187414932726461341686118949256090987887945793795111606127173070559161195798701868438493165699022987142999344491971501636954688384165654637572608847205231846548157215971161941739189685612882038176v-22.209183365386043415004702092068995458796882746556533582746811626940078831716147699141975616876757057326490754091070487340759673890666078034145331879732037644697308526976441373206852481312981515164531570514714277727825935255779907673910291997803996463254697686790482722143035983676168177334662112784778782339425656761310937414523449826528269487161957298001654383702286447935102245400075324031948212391186141611136915396285159499042077893604299422313895593796579558892032939576625890701506714565252891491624456217649910249358534417986105501847879874372084016082194743222964195247466582143048767142515186167268818095255712911995930340778579035314397585384714800735658771659292662771580375299071336178239909027925716010265386936999247402930585539571333975905103290122212676909150287478717938175028325415926233410778074949460525553632249848481265845873303341417191712002080971845606644954355560647394297517806939700009361097714082479256667599661219283300879143115021182512809875977396528600041660170u494877531821354279758645370161055856076950.7477240428448224377539095186399808811049003702017184860644725879464801087483221174190763808884166064055890124109855346403754648743861633277734495672788990339354611549410693619758146511305199696109051083715789433185746285841540794301923580216009864911624296826028870255578193248094446434106199172750653690309424660657072647474107493634585021023717648065298127550200653174174819305191376683728187070494612622267876067842211385079150792069459259900210390776262014342207604460887453101983717879961630503320361561275949517169759708497595048084140245693412961202011797451614525793829081184327059656099843834634902917369349685973633290967626120436663030640938938262252774201708785304384960850143150191413115486009838451699624122635180374545596610403468412281220039817199638090791097629886842983385935252340515496524917494446349327840748498925979910780056514070691489076651076116347673359730004137608310739596495546151047075672594195816559283397988234666230077357737" << "-key=24271977945124975509874347970887325414589535285430878493725143255815"
