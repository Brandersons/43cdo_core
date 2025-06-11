# Separated Squad Markers Feature

## Overview
This feature adds the ability to track and display markers for squad members from other groups who are separated from their leader beyond a configurable distance threshold. Settings are configured per device type (Android, MicroDAGR, Tablet) for maximum flexibility.

## Features

### 1. Separated Squad Member Markers
- Shows markers for squad members from other groups who are separated from their leader
- Configurable distance threshold per device (0-5000 meters, default: 200m)
- **Distance threshold is determined by the player's equipment**, not the separated member's equipment
- Markers appear in orange/amber color to distinguish from regular squad members
- Only shows members who have cTab equipment (ItemcTab, ItemAndroid, or ItemMicroDAGR)
- Device-specific settings: each device type can have different configurations

### Device Priority System
When the player has multiple cTab devices, the system uses the following priority order:
1. **Tablet** (ItemcTab) - Highest priority
2. **Android** (ItemAndroid) - Medium priority  
3. **MicroDAGR** (ItemMicroDAGR) - Lowest priority

If the player has no cTab equipment, the separated squad marker feature is disabled entirely.

### 2. CQB Mode Hotkey
- **Hotkey-based toggle** instead of device-specific settings
- When **enabled**: 
  - Stores current separation distance settings for all devices  
  - Sets all separation distances to 0 (shows ALL squad members from other groups)
  - Hides labels on separated squad member markers
- When **disabled**:
  - Restores previous separation distance settings for all devices
  - Shows labels again
- Global toggle affects all devices simultaneously
- Bindable hotkey in Controls > Configure Addons > cTab > "Toggle CQB Mode"
- Default: No key bound (must be set by user)

### 3. CBA Settings Integration
Settings are available in the CBA Addon Settings menu under "cTab" with separate categories for each device:

#### Android - Squad Markers
- **Enable Separated Squad Markers**: Enable/disable the feature for Android devices
- **Separation Distance**: Distance threshold in meters (0-5000m) for Android

#### MicroDAGR - Squad Markers
- **Enable Separated Squad Markers**: Enable/disable the feature for MicroDAGR devices
- **Separation Distance**: Distance threshold in meters (0-5000m) for MicroDAGR

#### Tablet - Squad Markers
- **Enable Separated Squad Markers**: Enable/disable the feature for Tablet devices
- **Separation Distance**: Distance threshold in meters (0-5000m) for Tablet

## Technical Details

### Device-Specific Operation
- Each device type (Android, MicroDAGR, Tablet) has independent distance settings
- **Separation distance is based on the player's highest priority device**
- Separated members are only shown if they carry cTab equipment AND the player has the feature enabled
- Settings are per-device to allow different configurations for different use cases

### CQB Mode Operation
- **Global hotkey** affects all devices simultaneously
- Temporarily overrides all separation distance settings by setting them to 0
- Stores original settings and restores them when disabled
- Provides instant feedback via system chat messages
- Labels are hidden globally when CQB mode is active

### Client-Side Operation
- All settings are client-side only and not synchronized between players
- Each client can configure their own preferences for each device type
- Markers update at the same rate as regular squad markers
- CQB mode state is maintained per client

### Performance Considerations
- Feature only processes when enabled for at least one device type
- Skips groups with only one member (leader)
- Uses efficient distance calculations
- Device-specific checking optimizes processing

### Immediate Updates
- Changing settings in CBA menu immediately updates markers
- CQB mode toggle provides immediate visual feedback
- No need to wait for next scheduled update cycle

## Files Modified

- `functions/fn_initSquadSeparationSettings.sqf` - Device-specific CBA settings initialization (CQB settings removed)
- `functions/fn_toggleCqbMode.sqf` - New function for hotkey-based CQB mode toggle
- `functions/fn_updateLists.sqf` - Extended to track separated members per device
- `functions/fn_drawBftMarkers.sqf` - Extended to draw separated member markers with global CQB mode
- `player_init.sqf` - Added CQB mode hotkey registration and removed CQB default values
- `CfgFunctions.h` - Added toggleCqbMode function definition

## Usage

### Initial Setup
1. Open CBA Addon Settings (ESC > Addon Options > cTab)
2. Navigate to the device-specific "Squad Markers" sections:
   - "Android - Squad Markers"
   - "MicroDAGR - Squad Markers" 
   - "Tablet - Squad Markers"
3. Configure your preferences for each device type:
   - Enable/disable the feature per device
   - Set separation distance threshold per device

### CQB Mode Setup
1. Open Controls > Configure Addons > cTab
2. Find "Toggle CQB Mode" and bind it to your preferred key combination
3. Use the hotkey during gameplay to toggle CQB mode on/off

### CQB Mode Usage
- **Toggle ON**: All squad members from other groups will show without labels (distance = 0)
- **Toggle OFF**: Returns to your configured distance thresholds with labels
- System chat will confirm the current state when toggled

## Example Use Cases

- **Different Distance Thresholds**: Set longer distances for Tablet (500m) and shorter for MicroDAGR (100m)
- **Selective Device Usage**: Enable only for Tablet and Android, disable for MicroDAGR
- **Quick CQB Toggle**: Instantly see all separated squad members during close quarters operations
- **Situational Awareness**: Use CQB mode temporarily to get full picture, then return to filtered view

The feature is designed to work seamlessly with existing cTab functionality and maintains compatibility with both singleplayer and multiplayer environments. 