#ifndef HOSTMANAGER_H
#define HOSTMANAGER_H

#include <QtGui/QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include "ui_host_switcher.h"
#include "load_config_dialog.h"
#include "set_hotkey_dialog.h"
#include "host_config.h"
#include <qxtglobalshortcut.h>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPushButton;
QT_END_NAMESPACE

class LoadConfigDialog;
class SetHotkeyDialog;

class HostSwitcher: public QWidget {
Q_OBJECT

public:
	HostSwitcher(QWidget *parent = 0);
	~HostSwitcher();

	static QString help_message;
	HostConfig *host_config_;
	QxtGlobalShortcut *scRestore;
	QxtGlobalShortcut *scSwitchDown;
	QxtGlobalShortcut *scSwitchUp;

	void resetItems();

	void bindHotkeys();

private:
	Ui::HostSwitcherClass ui;

    QAction *restoreAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
	LoadConfigDialog *load_config_dialog_;
	SetHotkeyDialog *setHotKeyDialog;

	void createTrayIcon();
	void resetTrayIconMenu();

	void swapItem(int rowA, int rowB);

public slots:
	void on_addItemButton_clicked();
	void on_deleteItemButton_clicked();

	void on_moveItemUpButton_clicked();
	void on_moveItemDownButton_clicked();

	void on_saveInfoButton_clicked();

	void on_itemListTableWidget_itemSelectionChanged();
	void on_itemListTableWidget_itemChanged(QTableWidgetItem *item);

	void on_contentEditor_undoAvailable(bool available);

	void iconActivated(QSystemTrayIcon::ActivationReason reason);

	void hostConfigTriggered(QAction *action);

	void switchItemUp();
	void switchItemDown();

	void showLoadConfigDialog();
	void showSetHotkeyDialog();

	void showHelpMessage();

};

#endif // HOSTMANAGER_H