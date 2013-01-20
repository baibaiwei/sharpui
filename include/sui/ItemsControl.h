// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ItemsControl.h
// ��  �ܣ�ʵ��Item�Ļ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// =============================================================

# ifndef _UIITEMSCONTROL_H_
# define _UIITEMSCONTROL_H_

#include <sui/sharpuiconfig.h>
#include <sui/scrollbar.h>
#include <suic/framework/uicontentcontrol.h>
#include <suic/tools/uielementcollection.h>
#include <sui/itemcontainer.h>

#include <sui/VisualizePanel.h>
#include <sui/ScrollViewer.h>

#define IMPLCHECKITEMS(dr,cr)\
    dr* pItem = dynamic_cast<dr*>(cr.get());\
    if (!pItem)\
    {\
        pItem = new dr();\
        pItem->SetContent(cr);\
        cr = pItem;\
    }\

namespace ui
{

class ItemCollection;

/// <summary>
/// ItemsControl,����ѡ����Ļ��ࡣ
/// </summary>
class SHARPUI_API ItemsControl : public suic::Control
{
public:

    ItemsControl();
    virtual ~ItemsControl();

    DeclareAbstractTypeofInfo(ItemsControl, suic::Control)

    suic::ObjectPtr FocusedItem() const;

public:

    bool HasItems() const;
    bool IsGrouping() const;

    ItemCollectionPtr GetItems() const;

    suic::Size MeasureItems(suic::Size availableSize, bool bHorz);

    int GetItemsCount() const;

    /// <summary>
    ///     �����������
    /// </summary>
    /// <remarks>
    ///     ������Ǵ�Element���������ʹ��TextBloch���а�װ
    /// </remarks>
    /// <param name="value">
    ///     �������
    /// </param>
    /// <returns>�����������</returns>
    int AddChild(suic::ObjectPtr value);
    int InsertChild(int index, suic::ObjectPtr value);
    int AddText(const suic::String& text);
    
    void RemoveChild(suic::ObjectPtr ePtr);

    virtual void RemoveAt(int iIndex);
    virtual void ClearChildren();

    virtual suic::ObjectPtr GetItem(int iIndex) const;
    virtual suic::String GetItemText(int iIndex) const;

    virtual void OnNotifyCollectionChanged(suic::ObjectPtr sender, suic::NotifyCollectionChangedArg& e);

public:

    suic::Element* GetChild(int index);
    suic::Int32 GetChildrenCount();

    virtual void OnItemsChanged(suic::NotifyCollectionChangedArg& e);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnUnloaded(suic::LoadedEventArg& e);

    void OnRender(suic::DrawingContext * drawing);

    void OnTextInput(suic::KeyboardEventArg& e);
    void OnKeyDown(suic::KeyboardEventArg& e);

    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);

    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

protected:

    virtual void InitializeScrollView();
    virtual void CheckAddingItem(suic::ObjectPtr& itemObj);

protected:

    // Ԫ�ش洢����
    ItemCollectionPtr _items;
    // ���ֶ���
    suic::PanelPtr _itemsHost;
    // ��ͼ����
    ScrollViewerPtr _scrollHost;
    //ScrollData _scrollData;
    // ��ǰӵ�н��������Ԫ��
    suic::ObjectPtr _focusedItem;
};

typedef suic::shared<ItemsControl> ItemsControlPtr;

inline suic::ObjectPtr ItemsControl::FocusedItem() const
{
    return _focusedItem;
}

};

# endif