/**
 * @file  PanelVolume.h
 * @brief Layer control panel.
 *
 */
/*
 * Original Author: Ruopeng Wang
 * CVS Revision Info:
 *    $Author: rpwang $
 *    $Date: 2008/10/22 15:25:40 $
 *    $Revision: 1.8 $
 *
 * Copyright (C) 2002-2009,
 * The General Hospital Corporation (Boston, MA). 
 * All rights reserved.
 *
 * Distribution, usage and copying of this software is covered under the
 * terms found in the License Agreement file named 'COPYING' found in the
 * FreeSurfer source code root directory, and duplicated here:
 * https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferOpenSourceLicense
 *
 * General inquiries: freesurfer@nmr.mgh.harvard.edu
 * Bug reports: analysis-bugs@nmr.mgh.harvard.edu
 *
 */
#ifndef PanelVolume_h
#define PanelVolume_h

#include <wx/wx.h>
#include "Listener.h"
#include "Broadcaster.h"
#include <vector>
#include "LUTDataHolder.h"

class wxAuiNotebook;
class wxListBox;
class wxCheckListBox;
class wxComboBox;
class wxChoice;
class wxTextCtrl;
class wxColorIndicator;
class Layer;
class LayerMRI;

class PanelVolume : public wxPanel, public Listener, public Broadcaster
{
public:
	PanelVolume(wxWindow* parent);
	virtual ~PanelVolume();
	
	void UpdateUI( bool bForce = false );
	
protected:
	void OnInternalIdle();
	
private:
	void OnSliderOpacityChanged( wxScrollEvent& event );
	void OnTextOpacityChanged( wxCommandEvent& event );
	void OnLayerSelectionChanged( wxCommandEvent& event );
	void OnLayerVisibilityChanged( wxCommandEvent& event );
	void OnListDoubleClicked( wxCommandEvent& event );
	
	void OnButtonNew( wxCommandEvent& event );
	void OnButtonLoad( wxCommandEvent& event );
	void OnButtonSave( wxCommandEvent& event );
	void OnButtonMoveUp( wxCommandEvent& event );
	void OnMoveUpUpdateUI( wxUpdateUIEvent& event );
	void OnButtonMoveDown( wxCommandEvent& event );
	void OnMoveDownUpdateUI( wxUpdateUIEvent& event );
	void OnButtonDelete( wxCommandEvent& event );
	void OnVolumeCloseUpdateUI( wxUpdateUIEvent& event );
	void OnVolumeLock( wxCommandEvent& event );
	void OnVolumeLockUpdateUI( wxUpdateUIEvent& event );
	void OnVolumeCopySetting( wxCommandEvent& event );
	void OnVolumeCopySettingUpdateUI( wxUpdateUIEvent& event );
	void OnVolumePasteSetting( wxCommandEvent& event );
	void OnVolumePasteSettingUpdateUI( wxUpdateUIEvent& event );
	void OnVolumePasteSettingAll( wxCommandEvent& event );
	void OnVolumePasteSettingAllUpdateUI( wxUpdateUIEvent& event );
	
	void OnCheckClearBackground( wxCommandEvent& event );
	void OnChoiceColorMap( wxCommandEvent& event );
	void OnChoiceLUT( wxCommandEvent& event );
	void OnColorSelectionChanged( wxCommandEvent& event );
	void OnTextFillValueChanged( wxCommandEvent& event );
	void OnTextWindowChanged( wxCommandEvent& event );
	void OnTextLevelChanged( wxCommandEvent& event );
	void OnSliderWindowChanged( wxScrollEvent& event );
	void OnSliderLevelChanged( wxScrollEvent& event );
	void OnTextHeatScaleMinChanged( wxCommandEvent& event );
	void OnTextHeatScaleMidChanged( wxCommandEvent& event );
	void OnTextHeatScaleMaxChanged( wxCommandEvent& event );
	void OnTextHeatScaleOffsetChanged( wxCommandEvent& event );
	void OnSliderHeatScaleMinChanged( wxScrollEvent& event );
	void OnSliderHeatScaleMidChanged( wxScrollEvent& event );
	void OnSliderHeatScaleMaxChanged( wxScrollEvent& event );
	void OnSliderHeatScaleOffsetChanged( wxScrollEvent& event );
	void OnTextMinJetScaleChanged( wxCommandEvent& event );
	void OnTextMaxJetScaleChanged( wxCommandEvent& event );
	void OnSliderMinJetScaleChanged( wxScrollEvent& event );
	void OnSliderMaxJetScaleChanged( wxScrollEvent& event );
	void OnCheckSmooth( wxCommandEvent& event );
	void OnChoiceDirectionCode( wxCommandEvent& event );
	void OnSliderFrameChanged( wxScrollEvent& event );
	void OnTextFrameChanged( wxCommandEvent& event );
	
	void DoUpdateUI();
	void ShowWidgets( std::vector<wxWindow*>& list, bool bShow );
	void PopulateColorTable( COLOR_TABLE* ct );
	void UpdateColorIndicator();
	
	void UpdateLayerList( Layer* layer );
			
	virtual void DoListenToMessage( std::string const iMsg, void* iData );
	
	void UpdateTextValue( wxTextCtrl* textctrl, double dvalue );
	
	wxCheckListBox*	m_listBoxLayers;
	wxButton*		m_btnMoveUp;
	wxButton*		m_btnMoveDown;
	wxButton*		m_btnNew;
	wxButton*		m_btnDelete;
	wxButton*		m_btnSave;
	wxSlider*		m_sliderOpacity;	
	wxTextCtrl*		m_textOpacity;
	wxCheckBox*		m_checkClearBackground;
	wxListBox*		m_listColorTable;
	wxChoice*		m_choiceColorMap;
	wxChoice*		m_choiceLUT;
	wxTextCtrl*		m_textDrawValue;
	wxTextCtrl*		m_textWindow;
	wxTextCtrl*		m_textLevel;
	wxSlider*		m_sliderWindow;
	wxSlider*		m_sliderLevel;
	wxTextCtrl*		m_textFileName;
	wxSlider*		m_sliderHeatScaleMin;
	wxSlider*		m_sliderHeatScaleMid;
	wxSlider*		m_sliderHeatScaleMax;
	wxSlider*		m_sliderHeatScaleOffset;
	wxTextCtrl*		m_textHeatScaleMin;
	wxTextCtrl*		m_textHeatScaleMid;
	wxTextCtrl*		m_textHeatScaleMax;
	wxTextCtrl*		m_textHeatScaleOffset;
	wxSlider*		m_sliderJetScaleMin;
	wxSlider*		m_sliderJetScaleMax;
	wxTextCtrl*		m_textJetScaleMin;
	wxTextCtrl*		m_textJetScaleMax;
	wxCheckBox*		m_checkSmooth;
	wxChoice*		m_choiceDirectionCode;
	wxColorIndicator*	m_colorIndicator;
	wxTextCtrl*		m_textFrame;
	wxSlider*		m_sliderFrame;
	
	std::vector<wxWindow*>	m_widgetlistGrayScale;
	std::vector<wxWindow*>	m_widgetlistHeatScale;
	std::vector<wxWindow*>	m_widgetlistJetScale;
	std::vector<wxWindow*>	m_widgetlistLUT;
	std::vector<wxWindow*>	m_widgetlistDirectionCode;
	std::vector<wxWindow*>	m_widgetlistFrame;
	
	LUTDataHolder*	m_luts;
	
	COLOR_TABLE*	m_curCTAB;
	
	bool			m_bUINeedUpdate;
	
	LayerMRI*		m_layerCopied;
    
	DECLARE_EVENT_TABLE()
};

#endif 

