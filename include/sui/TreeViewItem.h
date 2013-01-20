// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����TreeView.h
// ��  �ܣ�ʵ�ֱ�׼��ListView�ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// =======================================================

# ifndef _UITREEVIEWITEM_H_
# define _UITREEVIEWITEM_H_

#include <sui/sharpuiconfig.h>
#include <sui/selector.h>
#include <sui/checkbutton.h>
#include <sui/imagebox.h>
#include <sui/headereditemscontrol.h>

namespace ui
{

class TreeViewItem;
typedef suic::shared<TreeViewItem> TreeViewItemPtr;

typedef delegate<void(TreeViewItem*)> SelectTreeItemHandler;

/// <summary>
///  TreeViewItem��ʵ�����ڵ㡣
/// </summary>
class SHARPUI_API TreeViewItem : public HeaderedItemsControl
{
public:

    SelectTreeItemHandler ItemUnselected;
    SelectTreeItemHandler ItemSelected;

    TreeViewItem();
    TreeViewItem(const suic::String& text);

    DeclareTypeofInfo(TreeViewItem, HeaderedItemsControl)

    suic::PanelPtr GetHeaderHost();

    void Select();
    void Unselect();

    void SetCheck(bool value);
    bool IsChecked() const;

    bool RemoveItem(TreeViewItem* pItem);
    TreeViewItemPtr HitTreeItem(suic::Point pt);
    TreeViewItemPtr HitTreeItemByUserData(suic::ObjectPtr obj);

    void Expand();
    void Collapse();

    bool IsExpanded() const;
    bool IsSelectionActive() const;

    void ExpandSubtree();

    ImageBox* GetIcon();

    void ShowDotLine(bool show);
    void ShowExpandedButton(bool show);
    void ShowCheckButton(bool show);

    virtual void OnSelected(suic::RoutedEventArg& e);
    virtual void OnUnselected(suic::RoutedEventArg& e);

protected:

    bool CanExpand() const;

    void OnItemsChanged(suic::NotifyCollectionChangedArg& e);
    void OnInitialized();
    void OnStyleUpdated();

    void OnRender(suic::DrawingContext * drawing);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader);
    void OnPropertyChanged(suic::PropertyChangedEventArg& e);

    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);
    void OnLostFocus(suic::FocusEventArg& e);

    void OnStateChanged(suic::StateChangedEventArg& e);

    virtual void OnExpanded();
    virtual void OnCollapsed();

protected:

    // ����ͷ����
    suic::PanelPtr _headerContainer;

    // ���غ���ʾ��ť
    ui::ButtonPtr _expand;
    // ѡ��ť
    ui::CheckButton _check;
    // ͼ��
    ui::ImageBox _icon;

    // �ӽڵ�ƫ��
    int _internalIndent;

    bool _showDotLine;
};

inline void TreeViewItem::ShowDotLine(bool show)
{
    _showDotLine = show;
}

inline void TreeViewItem::ShowExpandedButton(bool show)
{
    _expand->SetVisible(show);
}

inline void TreeViewItem::ShowCheckButton(bool show)
{
    _check.SetVisible(show);
}

inline void TreeViewItem::SetCheck(bool value)
{
    _check.SetCheck(value);
}

inline bool TreeViewItem::IsChecked() const
{
    return _check.IsChecked();
}

};

# endif