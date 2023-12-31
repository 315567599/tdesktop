/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Api {
struct SendOptions;
} // namespace Api

namespace Ui {
class PopupMenu;
class RpWidget;
} // namespace Ui

namespace Data {
class Thread;
} // namespace Data

namespace SendMenu {

enum class Type {
	Disabled,
	SilentOnly,
	Scheduled,
	ScheduledToUser, // For "Send when online".
	Reminder,
};

enum class FillMenuResult {
	Success,
	None,
};

Fn<void()> DefaultSilentCallback(Fn<void(Api::SendOptions)> send);
Fn<void()> DefaultScheduleCallback(
	not_null<Ui::RpWidget*> parent,
	Type type,
	Fn<void(Api::SendOptions)> send);
Fn<void()> DefaultWhenOnlineCallback(Fn<void(Api::SendOptions)> send);

FillMenuResult FillSendMenu(
	not_null<Ui::PopupMenu*> menu,
	Type type,
	Fn<void()> silent,
	Fn<void()> schedule,
	Fn<void()> whenOnline);

void SetupMenuAndShortcuts(
	not_null<Ui::RpWidget*> button,
	Fn<Type()> type,
	Fn<void()> silent,
	Fn<void()> schedule,
	Fn<void()> whenOnline);

void SetupUnreadMentionsMenu(
	not_null<Ui::RpWidget*> button,
	Fn<Data::Thread*()> currentThread);

void SetupUnreadReactionsMenu(
	not_null<Ui::RpWidget*> button,
	Fn<Data::Thread*()> currentThread);

} // namespace SendMenu
