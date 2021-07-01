import { StatusBar } from 'expo-status-bar';
import React, { Image } from 'react';
import { Text, TextInput, View, TouchableHighlight } from 'react-native';
import { back, texts, buttons, views, images } from './styles'
import Icon from 'react-native-vector-icons/FontAwesome'

export default class MyDmPage extends React.Component {
    render() {
        return (
            <View style={{ flex: 1, backgroundColor: 'yellow' }}>
                <View style={views.top_bar}>
                    <View style={{ flex: 2, alignItems: 'center', justifyContent: 'center', paddingTop: 25 }}>
                        <Text style={texts.title_of_page}>Message</Text>
                    </View>
                </View>
                <View style={views.container}></View>
                <View style={views.bottom_bar}>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="home" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Home')} />
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="plus" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Home')} />
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="bookmark" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Home')} />
                    </View>
                </View>
                <StatusBar style="auto" />
            </View>
        )
    }
}